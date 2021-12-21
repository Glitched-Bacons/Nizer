#include <QTestCase.h>
#include <QtTest>


// Inherit after QTestCase!! \/\/\/
class SampleQtTest : public QTestCase
{
    Q_OBJECT

public:
    SampleQtTest();
    ~SampleQtTest();

private slots:
    void testcase_data();
    void testcase();
};

SampleQtTest::SampleQtTest()
{
    
}

SampleQtTest::~SampleQtTest()
{

}

void SampleQtTest::testcase_data()
{
    QTest::addColumn<uint>("input");
    QTest::addColumn<uint>("expectedresult");

    QTest::newRow("Example test case") << uint(0) << uint(0);

}

void SampleQtTest::testcase()
{
    QCOMPARE(0, 0);
}


// Define this static variable!
// static <NameOfClass> TEST_<NameOfClass>
static SampleQtTest TEST_SampleQtTest;

// Include <NameOfClass>.moc
#include "SampleQtTest.moc"
