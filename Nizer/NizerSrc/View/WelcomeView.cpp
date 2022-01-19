#include "WelcomeView.h"
#include "HomepageView.h"
#include <QFileDialog>
#include <filesystem>
#include <iostream>
#include <set>
#include <HashAlgorithm/AHash.h>
#include <HashAlgorithm/Hash.h>


const std::vector<std::string> WelcomeView::imageExtensions = {
  ".png", ".jpg", ".jpeg"
};

std::vector<std::unique_ptr<ClusterTile>> WelcomeView::loadFromFile()
{
    return std::vector<std::unique_ptr<ClusterTile>>();
}

void WelcomeView::createNewCluster(std::vector<std::unique_ptr<ClusterTile>>& clusters, const Hash& clusterHash, const std::string& initialFilePath)
{
    clusters.emplace_back(std::make_unique<ClusterTile>("Cluster " + std::to_string(clusters.size()), clusterHash));
    clusters.back()->addFilePath(initialFilePath);
}

ClusterTile& WelcomeView::findClosestCluster(std::vector<std::unique_ptr<ClusterTile>>& clusters, const Hash& hash)
{
    auto closestCluster = clusters.front().get();
    for(auto& cluster : clusters)
    {
        int hashDifference = hash - cluster->getHash();
        if(hashDifference < hash - closestCluster->getHash())
        {
            closestCluster = cluster.get();
        }
    }

    return *closestCluster;
}

std::vector<std::unique_ptr<ClusterTile>> WelcomeView::loadFromFolder()
{
    QFileDialog fileDialog;
    fileDialog.setFileMode(QFileDialog::Directory);
    auto folderWithImages = fileDialog.getExistingDirectory(nullptr, "Select folder with images", QDir::currentPath());

    auto clusters = std::vector<std::unique_ptr<ClusterTile>>();
    for (const auto& directory : std::filesystem::recursive_directory_iterator(folderWithImages.toStdString()))
    {
        auto extension = directory.path().extension().string();
        if(std::find(imageExtensions.cbegin(), imageExtensions.cend(), extension) != imageExtensions.cend())
        {
            auto imagePath = directory.path().string();
            auto imageHash = mHashAlgorithm->hash(imagePath);

            if(clusters.empty())
            {
                createNewCluster(clusters, imageHash, imagePath);
            }
            else
            {
                auto& closestCluster = findClosestCluster(clusters, imageHash);

                int hashDifference = imageHash - closestCluster.getHash();
                if(hashDifference < hashThreshold)
                {
                    closestCluster.addFilePath(imagePath);
                }
                else
                {
                    createNewCluster(clusters, imageHash, imagePath);
                }
            }
        }
    }

    return clusters;
}

void WelcomeView::selectAlgorithmClick()
{

}

void WelcomeView::threeDotsButtonClicked()
{
    ui->button_select_algorithm->setHidden(false);
}


WelcomeView::WelcomeView(ViewStack& viewStack, std::unique_ptr<HashAlgorithm> hashAlgorithm)
    : View(viewStack)
    , ui(std::make_unique<Ui::WelcomeView>())
    , mHashAlgorithm(std::move(hashAlgorithm))
{
    ui->setupUi(this);
    viewStack.setWindowSize(sizeHint());

    ui->button_select_algorithm->setHidden(true);

    connect(ui->button_threedots, &QPushButton::clicked, this, [this](){
        auto newState = !ui->button_select_algorithm->isHidden();
        ui->button_select_algorithm->setHidden(newState);
    });

    connect(ui->button_select_folder, &QPushButton::clicked, this, [this](){
        auto&& loadedData = loadFromFolder();
        requestPush<HomepageView>(std::move(loadedData));
        executeRequests();
    });

    connect(ui->button_load_saved_data, &QPushButton::clicked, this, [this](){
        requestPop();
        executeRequests();
    });

}
