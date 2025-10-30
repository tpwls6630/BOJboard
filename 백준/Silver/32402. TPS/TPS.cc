#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include <unordered_map>
#include <string>
using namespace std;

struct Point
{
    int x, y;
    Point &operator+=(const Point &other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }
    Point &operator-=(const Point &other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Point operator+(const Point &other) const
    {
        return {x + other.x, y + other.y};
    }

    Point operator-(const Point &other) const
    {
        return {x - other.x, y - other.y};
    }
};

void MR(Point &user, Point &cam)
{
    Point dir = cam - user;
    Point new_dir = {dir.y, -dir.x};
    cam = user + new_dir;
}

void ML(Point &user, Point &cam)
{
    Point dir = cam - user;
    Point new_dir = {-dir.y, dir.x};
    cam = user + new_dir;
}

int main()
{
    int n;
    cin >> n;

    Point user = {0, 0}, cam = {0, -1};
    unordered_map<string, function<void(Point &, Point &)>> moves;

    moves["MR"] = MR;
    moves["ML"] = ML;
    moves["W"] = [&](Point &user, Point &cam)
    {
        Point dir = user - cam;
        user += dir;
        cam += dir;
    };
    moves["S"] = [&](Point &user, Point &cam)
    {
        Point dir = user - cam;
        user -= dir;
        cam -= dir;
    };
    moves["A"] = [&](Point &user, Point &cam)
    {
        Point dir = user - cam;
        Point new_dir = {-dir.y, dir.x};
        cam += new_dir;
        user += new_dir;
    };
    moves["D"] = [&](Point &user, Point &cam)
    {
        Point dir = user - cam;
        Point new_dir = {dir.y, -dir.x};
        cam += new_dir;
        user += new_dir;
    };

    for (int i = 0; i < n; i++)
    {
        string cmd;
        cin >> cmd;
        moves[cmd](user, cam);
        printf("%d %d %d %d\n", user.x, user.y, cam.x, cam.y);
    }
    return 0;
}