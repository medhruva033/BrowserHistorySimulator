# Browser History Simulator (C++)

A console-based browser history simulator built using a manually
implemented doubly linked list in C++17.

## Features

- Visit new URLs
- Navigate backward and forward
- Display the current page
- View browsing history
- Search URLs by keyword
- Clear the complete history
- Discard forward history when visiting a new page

## Concepts Demonstrated

- Doubly linked lists
- Pointers and dynamic memory
- Object-oriented programming
- Node insertion and deletion
- Traversal and searching
- Memory management
- Input validation

## Project Structure

```text
BrowserHistorySimulator/
├── include/
│   └── BrowserHistory.h
├── src/
│   ├── BrowserHistory.cpp
│   └── main.cpp
├── README.md
└── .gitignore
```

## Requirements

- GCC/G++ compiler
- C++17 or later
- Visual Studio Code (recommended)

## Build

```cmd
g++ -std=c++17 -Wall -Wextra -Wpedantic -Iinclude src\main.cpp src\BrowserHistory.cpp -o browser.exe
```

## Run

```cmd
.\browser.exe
```

## How Navigation Works

Each history node points to its previous and next pages.

- **Back:** Moves to the previous node.
- **Forward:** Moves to the next node.
- **Visit:** Deletes any forward history, then adds a new node.
- **Clear:** Deletes all nodes and resets the history.

## Limitations

- History is stored in memory and disappears when the program exits.
- This is a navigation simulator, not a real web browser.
- URLs are not opened or validated against a website.

## Future Improvements

- Save and restore history from a file
- Remove individual history entries
- Add visit timestamps
- Implement automated tests

## Author

Dhruva M. K.

GitHub: [@medhruva033](https://github.com/medhruva033)
