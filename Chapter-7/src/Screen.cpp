#include <Screen.h>

// inline get
char Screen::get(pos ht, pos wd) const {
    pos row = ht * this->width;
    return this->contents[row + wd];
}

Screen& Screen::move(pos r, pos c) {
    this->cursor = r * width + c;
    return *this;
}

Screen& Screen::set(char c) {
    this->contents[this->cursor] = c;
    return *this;
}

Screen& Screen::set(pos ht, pos wd, char c) {
    this->contents[ht * this->width + wd] = c;
    return *this; 
}

// clear screen
void Window_mgr::clear(ScreenIndex id) {
    Screen &s = this->screens[id];
    s.contents = std::string(s.height * s.width, ' ');
}