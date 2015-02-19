/*
 * =====================================================================================
 *
 *       Filename:  sort_colors.cc
 *
 *    Description:  sort colors
 *
 *        Created:  02/19/2015 00:50:17
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

// sort colors in the order of red white blue
// red is 1
// white is 2
// blue is 3
void sortColors(vector<int> colors){
    if(colors.size() <= 1)  return;

    int red = 0;
    int blue = colors.size() - 1;
    int i = 0;

    while(i < blue){
        if(colors[i] == 0){
            swap(colors[i], colors[red++]);
        }

        if(colors[i] == 2){
            swap(colors[i], colors[blue--]);
            continue;
        }

        i++;
    }
}


