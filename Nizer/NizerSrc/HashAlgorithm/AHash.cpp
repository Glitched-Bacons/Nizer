#include "AHash.h"

#include <QImage>
#include <QRgb>
#include "Hash.h"

Hash AHash::hash(const std::string &imagePath) const
{
    // A temporary solution that should be improved in many ways
    QImage image(imagePath.c_str());

    // It would be nice to be able to choose the image size to which we scale the image
    image = image.scaled(32, 32);

    // I don't know if that's the best way to do it, and it's consistent with "AHash"
    auto pixelPtr = reinterpret_cast<QRgb*>(image.bits());
    auto pixelCount = image.width() * image.height();

    auto sumOfValues = 0;
    for (auto p = 0; p < pixelCount; p++) {
        sumOfValues += QColor(pixelPtr[p]).black();
    }

    return Hash(sumOfValues / pixelCount);

}
