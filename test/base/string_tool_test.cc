#include "gtest/gtest.h"
#include "base/string_tool.h"

namespace compass {
namespace base {
// testSuite event must use the macro TEST_F first parameter is classname
class StringToolSuiteTest:public testing::Test
{
protected:
    static void SetUpTestCase()
    {
        // you can new some share resource here.
        std::cout << "StringTool SuiteTest SetUPTestCase" << std::endl;
    }
    static void TearDownTestCase()
    {
        // release share resource here.
        std::cout << "StringTool SuiteTest TearDownTestCase" << std::endl;
    }
};

// testCase event must use the macro TEST_F first parameter is classname
class StringToolCaseTest:public testing::Test
{
protected:
    virtual void SetUp()
    {
        std::cout << "StringTool CaseTest SetUP" << std::endl;
    }
    virtual void TearDown()
    {
        std::cout << "StringTool CaseTest TearDown" << std::endl;
    }
};

TEST_F(StringToolSuiteTest, StringToInt)
{
	//std::cout << "max long value:" << std::numeric_limits<long>::max() << std::endl;  // max long is 9223372036854775807
    //std::cout << "max int value:" << std::numeric_limits<int>::max() << std::endl;    // max int is 2147483647
    //std::cout << "min long value:" << std::numeric_limits<long>::min() << std::endl;  // min long is -9223372036854775808
    //std::cout << "min int value:" << std::numeric_limits<int>::min() << std::endl;    // min ing is -2147483648
    const char* intStr[8] = {"12", "12abc", "abc12", "", "9223372036854775808", "2147483648", "-9223372036854775809", "-2147483649"};
    const char* errStr = nullptr;
    int i = StringTool::StringToInt(intStr[0], &errStr);
    EXPECT_EQ(i, 12); EXPECT_EQ(errStr, nullptr);

    i = StringTool::StringToInt(intStr[1], &errStr);
    EXPECT_EQ(i, 0); EXPECT_STREQ(errStr, "inconvertible");

    i = StringTool::StringToInt(intStr[2], &errStr);
    EXPECT_EQ(i, 0); EXPECT_STREQ(errStr, "inconvertible");

    i = StringTool::StringToInt(intStr[3], &errStr);
    EXPECT_EQ(i, 0); EXPECT_STREQ(errStr, "inconvertible");

    i = StringTool::StringToInt(intStr[4], &errStr);
    EXPECT_EQ(i, 0); EXPECT_STREQ(errStr, "too large");

    i = StringTool::StringToInt(intStr[5], &errStr);
    EXPECT_EQ(i, 0); EXPECT_STREQ(errStr, "too large");

    i = StringTool::StringToInt(intStr[6], &errStr);
    EXPECT_EQ(i, 0); EXPECT_STREQ(errStr, "too small");

    i = StringTool::StringToInt(intStr[7], &errStr);
    EXPECT_EQ(i, 0); EXPECT_STREQ(errStr, "too small");
}

TEST_F(StringToolSuiteTest, StringToDouble)
{
    //std::cout << "max positive double:" << std::numeric_limits<double>::max() << std::endl; // max double is 1.79769e+308
    //std::cout << "min negative double:" << -std::numeric_limits<double>::max() << std::endl; // max double is -1.79769e+308
    const char* doubleStr[6] = {"12.3", "12.3abc", "abc12.3", "", "1.79769e+309", "-1.79769e+309"};
    char const *errStr = nullptr;

    double d = StringTool::StringToDouble(doubleStr[0], &errStr);
    EXPECT_EQ(d, 12.3); EXPECT_EQ(errStr, nullptr);

    d = StringTool::StringToDouble(doubleStr[1], &errStr);
    EXPECT_EQ(d, 0); EXPECT_STREQ(errStr, "inconvertible");

    d = StringTool::StringToDouble(doubleStr[2], &errStr);
    EXPECT_EQ(d, 0); EXPECT_STREQ(errStr, "inconvertible");

    d = StringTool::StringToDouble(doubleStr[3], &errStr);
    EXPECT_EQ(d, 0); EXPECT_STREQ(errStr, "inconvertible");

    d = StringTool::StringToDouble(doubleStr[4], &errStr);
    EXPECT_EQ(d, 0); EXPECT_STREQ(errStr, "too large");

    d = StringTool::StringToDouble(doubleStr[5], &errStr);
    EXPECT_EQ(d, 0); EXPECT_STREQ(errStr, "too small");
}

}
}
