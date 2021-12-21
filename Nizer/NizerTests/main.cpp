#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <QtTest/QtTest>
#include "QTestCase.h"

int main(int argc, char *argv[]) {

    std::cout << "== Running QTests == \n" << std::endl;
    // setup lambda
    int status = 0;
    auto runTest = [&status, argc, argv](QObject* obj) {
        status |= QTest::qExec(obj, argc, argv);
    };

    // run suite
    auto &suite = QTestCase::suite();
    for (auto it = suite.begin(); it != suite.end(); ++it) {
        runTest(*it);
    }

    std::cout << "\n\n== Running GTests == \n" << std::endl;
  	::testing::InitGoogleTest(&argc, argv);
  	return RUN_ALL_TESTS();
}
