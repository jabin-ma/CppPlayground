#include <iostream>


void target_loads_test() {
    const char *config_str = "80 40000:1 500000:24 1485000:98";
    const char *cp;
    unsigned int *new_target_loads;
    int ntokens = 1;
    int i;
    cp = config_str;
    while ((cp = strpbrk(cp + 1, " :"))) {
        ntokens++;
    }
    new_target_loads = static_cast<unsigned int *>(malloc(ntokens * sizeof(unsigned int)));

    cp = config_str;
    i = 0;
    while (i < ntokens) {
        if (sscanf(cp, "%u", &new_target_loads[i++]) != 1) {
            // error
            std::cout << "ERROR" << std::endl;
        }
        cp = strpbrk(cp, " :");
        if (!cp) break;
        cp++;
        std::cout << " parse str:" << cp << std::endl;
    }


    for (i = 0; i < ntokens; i++) {
        std::cout << " ARRAY : [" << i << "]" << new_target_loads[i] << std::endl;
    }

    // find freq targer load

    unsigned int freq = 1485000;

    for (i = 0; i < ntokens - 1 && freq >= new_target_loads[i + 1]; i += 2) {
        std::cout << " FIND : [" << i << "]" << new_target_loads[i] << std::endl;
    }

    std::cout << "FIND RESULT: " << new_target_loads[i];
}


int main() {
    target_loads_test();
    return 0;
}
