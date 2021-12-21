#include <QObject>
#include <vector>

// SOURCE: https://alexhuszagh.github.io/2016/using-qttest-effectively/

/** \brief Base class for the test suite runner.
 */
class QTestCase: public QObject
{
public:
     QTestCase();

     static std::vector<QObject*> & suite();
};
