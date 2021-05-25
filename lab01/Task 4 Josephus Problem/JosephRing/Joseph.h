#pragma once

class PeopleNode {
private:
    int data;
    PeopleNode* nextPeople;
public:
    PeopleNode(int data) {
        this->data = data;
        nextPeople = nullptr;
    }

    int getData() {
        return data;
    }

    void setData(int peopleNumber) {
        data = peopleNumber;
    }

    PeopleNode* getNextPeople() {
        return nextPeople;
    }

    void setNextPeople(PeopleNode* nextPeople) {
        this->nextPeople = nextPeople;
    }
};
