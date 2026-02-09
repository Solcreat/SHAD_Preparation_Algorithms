#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int n, currentElement;
    int x_1 = 0, x_2 = 0, x_3 = 0, middleElement; // min(x_1, x_2, x_3) < middleElement < max(x_1, x_2, x_3)
    int minSum; // нам нужно минимизировать сумму трех чисел при максимальной частотности

    unordered_map<int, int> myMap; // числа и сколько раз они встретились

    cin >> n; // считываем общее количество чисел в массиве

    for (int i = 0; i < n; ++i) {

        cin >> currentElement; // считываем новый элемент в массиве

        if (myMap.count(currentElement) == 0) myMap[currentElement] = 1; // если этот элемент никогда не встречался, значит он встретился первый раз
        else myMap[currentElement] += 1; // если же встречался, то значит, что на один больше раз он теперь нам встретился

        if (x_1 == 0) { // считываем первый член в нашей тройке, этот блок выполнится в любом случае
            x_1 = currentElement;
            continue; // переходим к считыванию второго элемента
        }
        // этот блок выполнится лишь при 1) x_2 не равно какому-то числу, кроме нуля.
        if (x_2 == 0) {
            // 2) Только если текущий элемент ОТЛИЧАЕТСЯ от x_1
            if (x_1 != currentElement) x_2 = currentElement;
            continue;
        }
        // этот блок выполнится лишь при 1) x_3 не равно какому-то числу, кроме нуля.
        if (x_3 == 0) {
            // 2) Только если текущий элемент ОТЛИЧАЕТСЯ от x_1 И x_2
            if (x_1 != currentElement && x_2 != currentElement) {
                x_3 = currentElement;
                minSum = x_1 + x_2 + x_3; // считаем первую сумму из троек различных чисел, которые, будем считать, что минимальные.
                continue;
            }
        }
        // если текущий элемент отличается от всех трех чисел, значит, возможно наша тройка изменится.
        if (x_1 != currentElement && x_2 != currentElement && x_3 != currentElement) {

            // определяем middleElement

            if (min(x_1, min(x_2, x_3)) < x_1 && x_1 < max(x_1, max(x_2, x_3))) middleElement = x_1;
            else if (min(x_1, min(x_2, x_3)) < x_2 && x_2 < max(x_1, max(x_2, x_3))) middleElement = x_2;
            else if (min(x_1, min(x_2, x_3)) < x_3 && x_3 < max(x_1, max(x_2, x_3))) middleElement = x_3;

            // проверяем, выполняется ли для максимального x_i из тройки условие "на вылет".
            if (myMap[max(x_1, max(x_2, x_3))] <= myMap[currentElement]) {
                // если выполняется, что (сумма получается меньше И количество встреч у всех других элементов в тройке НЕ МЕНЬШЕ, чем у максимального) ИЛИ количество "встреч" больше, то беззаговорочно заменяем.
                if (((minSum > (currentElement + min(x_1, min(x_2, x_3)) + middleElement)) && \
                    (!(myMap[currentElement] > myMap[middleElement] || \
                        myMap[currentElement] > myMap[min(x_1, min(x_2, x_3))]))) || \
                    (myMap[max(x_1, max(x_2, x_3))] < myMap[currentElement])) {
                    minSum = currentElement + min(x_1, min(x_2, x_3)) + middleElement;
                    (max(x_1, max(x_2, x_3)) == x_1 ? x_1 : (max(x_2, x_3) == x_2 ? x_2 : x_3)) = currentElement;
                    continue; // переходим к следующему числу в массиве
                }
                // если же сумма получается такой же или даже большей и при этом количество "встреч" такое же, то пошло НАФИГ это число.
            }
            // проверяем, выполняется ли для middleElement (x_i) из тройки условие "на вылет".
            if (myMap[middleElement] <= myMap[currentElement]) {
                // если выполняется, что (сумма получается меньше И количество встреч у всех других элементов в тройке НЕ МЕНЬШЕ, чем у среднего) ИЛИ количество "встреч" больше, то беззаговорочно заменяем.
                if (((minSum > (currentElement + min(x_1, min(x_2, x_3)) + max(x_1, max(x_2, x_3)))) && \
                    (!(myMap[currentElement] > myMap[max(x_1, max(x_2, x_3))] || \
                        myMap[currentElement] > myMap[min(x_1, min(x_2, x_3))]))) || \
                    (myMap[middleElement] < myMap[currentElement])) {
                    minSum = currentElement + min(x_1, min(x_2, x_3)) + max(x_1, max(x_2, x_3));
                    (middleElement == x_1 ? x_1 : (middleElement == x_2 ? x_2 : x_3)) = currentElement;
                    continue; // переходим к следующему числу в массиве
                }
                // если же сумма получается такой же или даже большей и при этом количество "встреч" такое же, то пошло НАФИГ это число.
            }

            // проверяем, выполняется ли для минимального x_i из тройки условие "на вылет".
            if (myMap[min(x_1, min(x_2, x_3))] <= myMap[currentElement]) {
                // если выполняется, что сумма получается меньше или количество "встреч" больше, то беззаговорочно заменяем.
                if (((minSum > (currentElement + middleElement + max(x_1, max(x_2, x_3)))) && \
                    (!(myMap[currentElement] > myMap[middleElement] || \
                        myMap[currentElement] > myMap[max(x_1, max(x_2, x_3))]))) || \
                    (myMap[min(x_1, min(x_2, x_3))] < myMap[currentElement])) {
                    minSum = currentElement + middleElement + max(x_1, max(x_2, x_3));
                    (min(x_1, min(x_2, x_3)) == x_1 ? x_1 : (min(x_2, x_3) == x_2 ? x_2 : x_3)) = currentElement;
                    continue; // переходим к следующему числу в массиве
                }
                // если же сумма получается такой же или даже большей и при этом количество "встреч" такое же, то пошло НАФИГ это число.
            }
        }
    }
    if (x_1 == 0 || x_2 == 0 || x_3 == 0) {
        exit(0);
    }
    vector<int> myVector = { x_1, x_2, x_3 };
    int temp;
    bool noSort; // the flag of fact that nothing sorts
    // 3 2 1
    // standard Bubble sort.
    for (int i = 0; i < 3; ++i) {
        noSort = true;
        for (int j = 0; j < 2; ++j) {
            if (myVector[j] > myVector[j + 1]) {
                temp = myVector[j];
                myVector[j] = myVector[j + 1];
                myVector[j + 1] = temp; // 2 3 1, 2 1 3, 1 2 3
                noSort = false;
            }
        }
        if (noSort) break;
    }

    cout << myVector[0] << " " << myVector[1] << " " << myVector[2] << endl;
    return 0;
}