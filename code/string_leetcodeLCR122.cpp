/*
 * @Author: Jean_Leung
 * @Date: 2024-09-21 12:32:30
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-21 12:32:41
 * @FilePath: \code\string_leetcodeLCR122.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define random(x) (rand() % x)
using namespace std;
class Solution {
  public:
    string pathEncryption(string path) {
        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '.') {
                path[i] = ' ';
            }
        }
        return path;
    }
};