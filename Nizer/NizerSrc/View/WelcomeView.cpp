#include "WelcomeView.h"
#include "HomepageView.h"
#include <filesystem>
#include <iostream>

std::vector<std::unique_ptr<ClusterTile>> WelcomeView::loadFromFile()
{
    // Placeholder
    //for (std::filesystem::recursive_directory_iterator i("."), end; i != end; ++i)
      //if (!is_directory(i->path()))
        //std::cout << i->path().filename() << "\n";

    static const std::vector<std::string> imageExtensions = {
      ".png", ".jpg", ".jpeg"
    };

    // Just for test purposes
    auto clusters = std::vector<std::unique_ptr<ClusterTile>>();
    int counter = 0;
    int clusterNumber = 0;
    for (const auto& dirEntry : std::filesystem::recursive_directory_iterator("."))
    {
        auto extension = dirEntry.path().extension().string();
        if(std::find(imageExtensions.cbegin(), imageExtensions.cend(), extension) != imageExtensions.cend())
        {
            if(counter == 0)
            {
                clusters.emplace_back(std::make_unique<ClusterTile>("cluster " + std::to_string(clusterNumber++)));
            }
            auto& back = clusters.back();
            back->addFilePath(dirEntry.path().string());

            counter += 1;
            counter %= 4;
        }
    }

    return clusters;
}

std::vector<ClusterTile> WelcomeView::loadFromFolder()
{
    return std::vector<ClusterTile>();
}

void WelcomeView::selectAlgorithmClick()
{

}

void WelcomeView::threeDotsButtonClicked()
{
    ui->button_select_algorithm->setHidden(false);
}


WelcomeView::WelcomeView(ViewStack& viewStack)
    : View(viewStack)
    , ui(std::make_unique<Ui::WelcomeView>())
{
    ui->setupUi(this);
    viewStack.setWindowSize(sizeHint());

    ui->button_select_algorithm->setHidden(true);

    loadedFiles = loadFromFile();

    connect(ui->button_threedots, &QPushButton::clicked, this, [this](){
        auto newState = !ui->button_select_algorithm->isHidden();
        ui->button_select_algorithm->setHidden(newState);
    });

    connect(ui->button_select_folder, &QPushButton::clicked, this, [this](){
        requestPush<HomepageView>(std::move(loadedFiles));
        executeRequests();
    });

    connect(ui->button_load_saved_data, &QPushButton::clicked, this, [this](){
        requestPop();
        executeRequests();
    });

}
