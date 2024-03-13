#include "User.h"
#include <cstring>
#include <iostream>

using std::cout;
using std::endl;

int User::n_user = 0;

// ctor, parameter: nama pengguna
User::User(char *name)
{
    this->name = new char[strlen(name)];
    strcpy(this->name, name);
    num_of_favourite_music = 0;
    music_list = new char *[20];
    n_user++;
}

// cctor
User::User(const User &user)
{
    name = new char[strlen(user.name)];
    strcpy(name, user.name);
    num_of_favourite_music = user.num_of_favourite_music;
    music_list = new char *[20];
    for (int i = 0; i < user.num_of_favourite_music; i++)
    {
        music_list[i] = new char[strlen(user.music_list[i])];
        strcpy(music_list[i], user.music_list[i]);
    }

    n_user++;
}

// dtor
// selain implementasi, print juga "User <nama user> deleted<endl>"
// Contoh:
// User A deleted
//
User::~User()
{
    delete[] name;
    for (int i = 0; i < num_of_favourite_music; i++)
    {
        delete[] music_list[i];
    }

    delete[] music_list;
    n_user--;
    cout << "User " << name << " deleted" << endl;
}

// Asumsi: musik unik, parameter: judul musik

void User::addFavouriteMusic(char *music_title)
{
    if (num_of_favourite_music < 20)
    {
        music_list[num_of_favourite_music] = new char[strlen(music_title)];
        strcpy(music_list[num_of_favourite_music], music_title);
        num_of_favourite_music++;
    }
}

void User::deleteFavouriteMusic(char *music_title)
{
    if (num_of_favourite_music > 0)
    {
        if (num_of_favourite_music == 1)
        {
            if (strcmp(music_list[0], music_title) == 0)
            {
                num_of_favourite_music--;
            }
        }
        else
        {
            for (int i = 0; i < num_of_favourite_music; i++)
            {
                if (strcmp(music_list[i], music_title) == 0)
                {
                    num_of_favourite_music--;
                    int p = i;
                    while (p < num_of_favourite_music)
                    {
                        strcpy(music_list[p], music_list[p + 1]);
                        p++;
                    }

                    break;
                }
            }
        }
    }
}

void User::setName(char *name)
{
    strcpy(this->name, name);
}

char *User::getName() const
{
    return name;
}

int User::getNumOfFavouriteMusic() const
{
    return num_of_favourite_music;
}

// format print:
// <No>. <Judul musik><endl>
// contoh:
// 1. Starship - Nicki Minaj
// 2. To Be Human - Sia, Labrinth
//
// jika tidak ada musik, print: "No music in your favourite list<endl>"
void User::viewMusicList() const
{
    if (num_of_favourite_music < 1)
    {
        cout << "No music in your favourite list" << endl;
    }
    else
    {
        for (int i = 0; i < num_of_favourite_music; i++)
        {
            cout << i + 1 << ". " << music_list[i] << endl;
        }
    }
}

int User::getNumOfUser()
{
    return n_user;
}
