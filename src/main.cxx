#include <iostream>

#include "func_map.h"

using namespace std;

//call every module's start function here!
BEGIN_FUNC_MAP()
    FUNC_ITEM_IF(true, module_run)
END_FUNC_MAP()

static void init() {
    // call function map
    CALL_FUNC_MAP()
    ;

}

int main() {
    init();

    return 0;
}
