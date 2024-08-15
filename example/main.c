#include "../include/apiClient.h"

int main(int argc, char const *argv[])
{
    const client = apiClient_create();
    apiClient_free(client);
    return 0;
}
