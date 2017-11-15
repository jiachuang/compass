#ifndef COMPASS_BASE_STRING_TOOL_H_
#define COMPASS_BASE_STRING_TOOL_H_

namespace compass {
namespace base {
   
class StringTool
{
public:
    static int StringToInt(char const *intStr, char const **errStr);
    static double StringToDouble(char const *doubleStr, char const **errStr);
};

}
}

#endif // COMPASS_BASE_STRING_TOOL_H_
