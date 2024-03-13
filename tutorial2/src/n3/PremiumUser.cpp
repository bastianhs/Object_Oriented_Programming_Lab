#include "PremiumUser.h"
#include <iostream>

using std::cout;
using std::endl;

// ctor, active = true, parameter: nama pengguna
PremiumUser::PremiumUser(char *name) : User(name)
{
    num_of_music_downloaded = 0;
    active = true;
}

// cctor
// implementasikan jika diperlukan,
// jika tidak diperlukan, hapus cctor
// jika perlu diimplementasikan, print "Premium User Copied<endl>"
PremiumUser::PremiumUser(const PremiumUser &premium_user) : User(premium_user)
{
    num_of_music_downloaded = premium_user.num_of_music_downloaded;
    active = premium_user.active;
    cout << "Premium User Copied" << endl;
}

// dtor; implementasikan jika diperlukan
// jika tidak diperlukan, hapus dtor
// jika diperlukan
// selain implementasi, print juga "Premium user <nama user> deleted<endl>"
// Contoh:
// Premium user A deleted
PremiumUser::~PremiumUser()
{
    cout << "Premium user " << name << " deleted" << endl;
}

// print kata-kata sbg. berikut: "Music Downloaded: <judul><endl>"
// Contoh:
// Music Downloaded: Loyal - Chris Brown, Lil Wayne, Tyga
//
// Jika akun premium tidak aktif, print: "Activate premium account to download music<endl>"
void PremiumUser::downloadMusic(char *music_title)
{
    if (!active)
    {
        cout << "Activate premium account to download music" << endl;
    }
    else
    {
        cout << "Music Downloaded: " << music_title << endl;
        num_of_music_downloaded++;
    }
}

void PremiumUser::inactivatePremium()
{
    active = false;
}

void PremiumUser::activatePremium()
{
    active = true;
}

int PremiumUser::getNumOfMusicDownloaded() const
{
    return num_of_music_downloaded;
}

// mengembalikan nilai active
bool PremiumUser::getPremiumStatus() const
{
    return active;
}
