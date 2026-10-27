
#pragma once

#include <string>

struct HistoryNode {
    std::string url;
    HistoryNode* prev;
    HistoryNode* next;

    explicit HistoryNode(const std::string& pageUrl)
        : url(pageUrl), prev(nullptr), next(nullptr) {}
};

class BrowserHistory {
private:
    HistoryNode* head;
    HistoryNode* tail;
    HistoryNode* current;
    int size;

    void deleteForwardHistory();

public:
    BrowserHistory();
    ~BrowserHistory();

    BrowserHistory(const BrowserHistory&) = delete;
    BrowserHistory& operator=(const BrowserHistory&) = delete;

    void visit(const std::string& url);
    void goBack();
    void goForward();
    void showCurrentPage() const;
    void showHistory() const;
    void searchHistory(const std::string& keyword) const;
    void clearHistory();
    bool isEmpty() const;
};
