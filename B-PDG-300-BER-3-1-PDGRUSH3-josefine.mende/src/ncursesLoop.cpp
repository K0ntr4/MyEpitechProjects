/*
** EPITECH PROJECT, 2022
** B-PDG-300-BER-3-1-PDGRUSH3-josefine.mende
** File description:
** ncursesLoop
*/

#include "../include/TextMonitor.hpp"
#include <curses.h>
#include <unistd.h>
#include <string.h>

#define DISABLED_BOX 1
#define ENABLED_BOX 2

int drawSideBorders(int startX, int windowY)
{
    mvprintw(startX, 0, "|");
    mvprintw(startX, windowY - 1, "|");
    startX++;
    return startX;
}

int drawHelp(int startX, int windowY, TextMonitor monitor)
{
    const char *title = "Help";

    mvprintw(startX, 0, "+");
    mvprintw(startX, windowY - 1, "+");
    for (int i = 1; i < (windowY - 1); i++) {
        mvprintw(startX, i, "-");
    }
    startX++;
    attron(A_BOLD);
    mvprintw(startX, 2, title);
    attroff(A_BOLD);
    mvprintw(startX, 14, "Press Q to Exit");
    startX = drawSideBorders(startX, windowY);
    if (monitor.getCPUModule().getActivated()) {
        attron(COLOR_PAIR(ENABLED_BOX));
        mvprintw(startX, 2, "Show CPU: Press C");
        attroff(COLOR_PAIR(ENABLED_BOX));
    } else {
        attron(COLOR_PAIR(DISABLED_BOX));
        mvprintw(startX, 2, "Show CPU: Press C");
        attroff(COLOR_PAIR(DISABLED_BOX));
    }
    if (monitor.getDateModule().getActivated()) {
        attron(COLOR_PAIR(ENABLED_BOX));
        mvprintw(startX, 24, "Show Date: Press D");
        attroff(COLOR_PAIR(ENABLED_BOX));
    } else {
        attron(COLOR_PAIR(DISABLED_BOX));
        mvprintw(startX, 24, "Show Date: Press D");
        attroff(COLOR_PAIR(DISABLED_BOX));
    }
    startX = drawSideBorders(startX, windowY);
    
    if (monitor.getNetworkModule().getActivated()) {
        attron(COLOR_PAIR(ENABLED_BOX));
        mvprintw(startX, 2, "Show Network: Press N");
        attroff(COLOR_PAIR(ENABLED_BOX));
    } else {
        attron(COLOR_PAIR(DISABLED_BOX));
        mvprintw(startX, 2, "Show Network: Press N");
        attroff(COLOR_PAIR(DISABLED_BOX));
    }
    if (monitor.getOSKernelModule().getActivated()) {
        attron(COLOR_PAIR(ENABLED_BOX));
        mvprintw(startX, 24, "Show System: Press O");
        attroff(COLOR_PAIR(ENABLED_BOX));
    } else {
        attron(COLOR_PAIR(DISABLED_BOX));
        mvprintw(startX, 24, "Show System: Press O");
        attroff(COLOR_PAIR(DISABLED_BOX));
    }
    startX = drawSideBorders(startX, windowY);
    
    if (monitor.getRAMModule().getActivated()) {
        attron(COLOR_PAIR(ENABLED_BOX));
        mvprintw(startX, 2, "Show RAM: Press R");
        attroff(COLOR_PAIR(ENABLED_BOX));
    } else {
        attron(COLOR_PAIR(DISABLED_BOX));
        mvprintw(startX, 2, "Show RAM: Press R");
        attroff(COLOR_PAIR(DISABLED_BOX));
    }
    if (monitor.getUsernameModule().getActivated()) {
        attron(COLOR_PAIR(ENABLED_BOX));
        mvprintw(startX, 24, "Show Username: Press U");
        attroff(COLOR_PAIR(ENABLED_BOX));
    } else {
        attron(COLOR_PAIR(DISABLED_BOX));
        mvprintw(startX, 24, "Show Username: Press U");
        attroff(COLOR_PAIR(DISABLED_BOX));
    }
    startX = drawSideBorders(startX, windowY);
    mvprintw(startX, 0, "+");
    mvprintw(startX, windowY - 1, "+");
    for (int i = 1; i < (windowY - 1); i++) {
        mvprintw(startX, i, "-");
    }
    startX++;
    return startX;
}

TextMonitor activatedModules(int ch, TextMonitor monitor)
{
    switch (ch) {
        case 'c':
            monitor.getCPUModule().activate();
            break;
        case 'd':
            monitor.getDateModule().activate();
            break;
        case 'n':
            monitor.getNetworkModule().activate();
            break;
        case 'o':
            monitor.getOSKernelModule().activate();
            break;
        case 'r':
            monitor.getRAMModule().activate();
            break;
        case 'u':
            monitor.getUsernameModule().activate();
    }
    return monitor;
}

void ncursesLoop(TextMonitor monitor)
{
    int parentX = 0;
    int parentY = 0;
    int curX = 0;
    int curY = 0;
    int line = 0;
    int ch = 0;

    initscr();
    if (has_colors() == FALSE) {
        endwin();
        std::cout << "No color support." << std::endl;
        exit(1);
    }
    start_color();
    init_pair(DISABLED_BOX, COLOR_GREEN, COLOR_BLACK);
    init_pair(ENABLED_BOX, COLOR_RED, COLOR_BLACK);
    curs_set(0);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    noecho();
    getmaxyx(stdscr, parentX, parentY);
    while ((ch = getch()) != 'q')
    {
        erase();
        monitor = activatedModules(ch, monitor);
        monitor.updateModules();
        line = 0;
        getmaxyx(stdscr, curX, curY);
        if (curX != parentX || curY != parentY) {
            parentX = curX;
            parentY = curY;
        }
        if (curX < 10 || curY <= 50) {
            mvprintw(curX / 2, (curY - 20) / 2, "%s", "Resize the Window.\n");
            refresh();
            continue;
        }
        line = monitor.display(parentY);
        line = drawHelp(line, parentY, monitor);
        refresh();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    endwin();
}
