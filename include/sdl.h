#ifndef IFMOVE_SDL_H
#define IFMOVE_SDL_H

class SDL {
    public:
        SDL();
        ~SDL();
    private:
        bool init();
        bool quit();
};

#endif
