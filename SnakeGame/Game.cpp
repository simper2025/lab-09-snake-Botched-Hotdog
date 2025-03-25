#include "GameManager.h"

int main() {

    //Uncomment the next four lines to see console color options 0-255
    //for (int i = 0; i < 255; i++) {
    //    setcolor(i);
    //    _cprintf("Color option: %i. Hello, world.\n", i);
    //}

    GameManager Manager = GameManager(0.3, { 20,20 });
    while (Manager.ShouldContinueGame())
    {
        Manager.RunGame();
    }
	return 0;
}


