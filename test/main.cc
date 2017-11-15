#include <iostream>
#include "gtest/gtest.h"
namespace compass {
namespace base {
//global event. must call testing::AddGlobalTestEnvironment in main
class BaseEnvironment : public testing::Environment
{
public:
    virtual void SetUp()
    {
        std::cout << "Base global Environment SetUP" << std::endl;
    }
    virtual void TearDown()
    {
        std::cout << "Base global Environment TearDown" << std::endl;
    }
};

int main(int argc, char **argv) {
    printf("Running main() from gtest_main.cc\n");
    testing::AddGlobalTestEnvironment(new BaseEnvironment);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

}
}
