#ifndef SCREEN_H
#define SCREEN_H

#include <Window_mgr.h>
#include <iostream>
#include <string>

class Screen {
    // friend class Window_mgr;    //!< declare Window_mgr as friend class,
                                //!< Window_mgr can access private member
    friend void Window_mgr::clear(ScreenIndex);    //!< declare Window_mgr method as friend
public:
    using pos = std::string::size_type;
public:
    Screen() = default;    //!< default constructor
    /**
     * constructor with height and width
     * \param ht height
     * \param wd width
     * \param c character to fill the screen
     */
    Screen(pos ht, pos wd, char c) : height   (ht)
                                   , width    (wd)
                                   , contents (ht * wd, c) {}
    //! return character at cursor place, implicitly inlined
    char get() const { return contents[this->cursor]; }
    /**
     * return character at specific place
     * \param ht y coordinate
     * \param wd x coordinate
     * \return character at (ht, wd)
     */
    char get(pos ht, pos wd) const;
    //! move cursor return lvalue of this pointer
    Screen &move(pos r, pos c);
public:
    //! set character at cursor
    Screen &set(char c);
    //! set character at specific location
    Screen &set(pos ht, pos wd, char c);
public:
    //! non const class object display
    inline Screen &display(std::ostream &os) {
        this->do_display(os);    // int this do_display call the non-constant 
                                 // 'this' pointer is implicitly converted to
                                 // a constant 'this' pointer 
        return *this;
    }
    //! const class object display, constness overload
    inline const Screen &display(std::ostream &os) const {
        this->do_display(os);
        return *this;
    }
private:
    pos cursor = 0;
    pos height = 0;
    pos width  = 0;
    std::string contents;
private:
    mutable size_t access_counter = 0;    //!< this counter can be changed even in const object
    //! even this point to const object, counter is mutable
    inline void increase() const { this->access_counter++; }
private:
    //! helper display function
    inline void do_display(std::ostream &os) const { os << this->contents; }
};

#endif