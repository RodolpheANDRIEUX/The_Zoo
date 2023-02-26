//
// Created by rodol on 23/02/2023.
//

#include "../headers/Chicken.h"

void Chicken::sayHi() {
    if (female){
        cout << "cluck cluck..." << endl;
        return;
    }
    cout << "cock-a-doodle-doooo!" << endl;
}
