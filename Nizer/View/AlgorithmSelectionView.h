#ifndef ALGORITHMSELECTIONVIEW_H
#define ALGORITHMSELECTIONVIEW_H

#include "View.h"

#include <QGroupBox>
#include <HashAlgorithm/HashAlgorithm.h>

class AlgorithmSelectionView : public View
{
public:
    void save();
    void selectAlgorithmClick(bool isChecked);

private:
    QGroupBox mGroupBox;
    std::unique_ptr<HashAlgorithm> mHashAlgorithm;
};

#endif // ALGORITHMSELECTIONVIEW_H
