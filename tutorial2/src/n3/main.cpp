#include "User.h"
#include "PremiumUser.h"
#include "ArtistUser.h"

int main()
{
    User u1 = User("User-1");
    User u2 = User("User-2");
    User pu1 = User("Premium User-1");
    User pu2 = User("Premium User-2");
    User au1 = User("Artist User-1");
    User au2 = User("Artist User-2");

    u1.addFavouriteMusic("ABCDefgh");
    u1.addFavouriteMusic("qewqe123132");
    u1.addFavouriteMusic("zxcvzz123132");
    u1.viewMusicList();

    // u1.deleteFavouriteMusic("qewqe123132");
    // u1.viewMusicList();

    return 0;
}