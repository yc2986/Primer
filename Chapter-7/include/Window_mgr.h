#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H

#include <string>
#include <vector>

class Screen;    //!< forward declare Screen class to use in Window_mgr

class Window_mgr {
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex id);    //!< clear screen, reset all characters to ' '
private:
    //std::vector<Screen> screens{Screen(24, 80, ' ')};    //!< in class initialization
    std::vector<Screen> screens;    //!< to split Window_mgr and Screen classes
                                    //!< this cannot use in class init
};

#endif