#include "SDL.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <windows.h>
using namespace std;

int main(int argc,char ** argv) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		cout << SDL_GetError() << endl;
		return 1;
	}
	SDL_Window *win = nullptr;
	win = SDL_CreateWindow("hello world!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
	if (win == nullptr) {
		cout << "1"<<SDL_GetError() << endl;
        Sleep(2000);
		return 1;
	}
    SDL_Renderer *ren = nullptr;
    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == nullptr) {
        cout << "2"<<SDL_GetError() << endl;
        Sleep(2000);
        return 1;
    }
    SDL_Surface *bmp = nullptr;
    bmp = SDL_LoadBMP("../res/hello.bmp");
    if (bmp == nullptr) {
        cout <<"3"<< SDL_GetError() << endl;
        Sleep(2000);
        return 1;
    }
    SDL_Texture *tex = nullptr;
    tex = SDL_CreateTextureFromSurface(ren, bmp);
    SDL_FreeSurface(bmp);
    SDL_RenderClear(ren);
    SDL_RenderCopy(ren, tex, NULL, NULL);
    SDL_RenderPresent(ren);
    SDL_Delay(3000);
    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}
