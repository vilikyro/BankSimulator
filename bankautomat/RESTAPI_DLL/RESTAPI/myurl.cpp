#include "myurl.h"

MyUrl::MyUrl()
{
    base_url = "http://localhost:3000";
}

QString MyUrl::getBase_url() const
{
    return base_url;
}
