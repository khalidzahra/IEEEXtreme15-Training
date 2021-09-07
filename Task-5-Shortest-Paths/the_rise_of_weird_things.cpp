/*

    Bangalore City, where peace prevails most of the time. Not everyone is a huge fan of peace, though. Certainly not Mr. XYZ, whose identity is not known to us - yet. Mr. XYZ has somehow managed to bring vampires and zombies to Bangalore City to attack and destroy the city.

    Fatal Eagle, an ordinary citizen of the city is extremely worried on seeing his city being attacked by these weird creatures. But, as of now, he has no power to stop these creatures from their silent attacks. He wants to analyze these creatures firstly. He figured out some things about these creatures, like:

    Zombies have power in terms of an EVEN number.
    Vampires have power in terms of an ODD number.
    If he sees a zombie or a vampire, he marks them in his list with their power. After generating the entire list of power of these creatures, he decides to arrange this data in the following manner:

    All the zombies arranged in sorted manner of their power, followed by the total power of zombies.
    All the vampires arranged in sorted manner of their power, followed by the total power of vampires.
    You've to help him produce the following list to help him save his city.

 */

#include "bits/stdc++.h"

using namespace std;

int findSum(vector<int> &v) {
    int sum = 0;
    for (int i : v) sum += i;
    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<int> l(n), z, v;
    for (int i = 0; i < n; i++) cin >> l[i];
    for (int i : l) {
        if (i % 2 == 0) z.push_back(i);
        else v.push_back(i);
    }
    sort(z.begin(), z.end());
    sort(v.begin(), v.end());
    for (int i : z) cout << i << " ";
    cout << findSum(z) << " ";
    for (int i : v) cout << i << " ";
    cout << findSum(v);
    return 0;
}

