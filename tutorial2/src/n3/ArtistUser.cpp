#include "ArtistUser.h"
#include <cstring>
#include <iostream>

using std::cout;
using std::endl;

int ArtistUser::num_of_artist = 0;

// ctor, parameter: nama pengguna
ArtistUser::ArtistUser(char *name) : User(name)
{
    num_of_music_uploaded = 0;
    uploaded_music_list = new char *[20];
    num_of_artist++;
}

// cctor
ArtistUser::ArtistUser(const ArtistUser &artist_user) : User(artist_user)
{
    num_of_music_uploaded = artist_user.num_of_music_uploaded;
    uploaded_music_list = new char *[20];
    for (int i = 0; i < artist_user.num_of_music_uploaded; i++)
    {
        uploaded_music_list[i] = new char[strlen(artist_user.uploaded_music_list[i])];
        strcpy(uploaded_music_list[i], artist_user.uploaded_music_list[i]);
    }

    num_of_artist++;
}

// dtor
// selain implementasi, print juga "Artist user <nama user> deleted"
// Contoh:
// Artist user A deleted
ArtistUser::~ArtistUser()
{
    for (int i = 0; i < num_of_music_uploaded; i++)
    {
        delete[] uploaded_music_list[i];
    }

    delete[] uploaded_music_list;
    num_of_artist--;
    cout << "Artist user " << name << " deleted" << endl;
}

// Asumsi: musik unik, parameter: judul musik

void ArtistUser::uploadMusic(char *music_title)
{
    if (num_of_music_uploaded < 20)
    {
        uploaded_music_list[num_of_music_uploaded] = new char[strlen(music_title)];
        strcpy(uploaded_music_list[num_of_music_uploaded], music_title);
        num_of_music_uploaded++;
    }
}

void ArtistUser::deleteUploadedMusic(char *music_title)
{
    if (num_of_music_uploaded > 0)
    {
        if (num_of_music_uploaded == 1)
        {
            if (strcmp(uploaded_music_list[0], music_title) == 0)
            {
                num_of_music_uploaded--;
            }
        }
        else
        {
            for (int i = 0; i < num_of_music_uploaded; i++)
            {
                if (strcmp(uploaded_music_list[i], music_title) == 0)
                {
                    num_of_music_uploaded--;
                    int p = i;
                    while (p < num_of_music_uploaded)
                    {
                        strcpy(uploaded_music_list[p], uploaded_music_list[p + 1]);
                        p++;
                    }

                    break;
                }
            }
        }
    }
}

// format print:
// <No>. <Judul musik><endl>
// contoh:
// 1. Starship - Nicki Minaj
// 2. To Be Human - Sia, Labrinth
//
// jika tidak ada musik, print: "No music uploaded<endl>"
void ArtistUser::viewUploadedMusicList() const
{
    if (num_of_music_uploaded < 1)
    {
        cout << "No music uploaded" << endl;
    }
    else
    {
        for (int i = 0; i < num_of_music_uploaded; i++)
        {
            cout << i + 1 << ". " << uploaded_music_list[i] << endl;
        }
    }
}

int ArtistUser::getNumOfMusicUploaded() const
{
    return num_of_music_uploaded;
}

int ArtistUser::getNumOfArtist()
{
    return num_of_artist;
}
