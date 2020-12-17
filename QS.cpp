#include "QS.h"

    int *table;
    int sizeArray = 0;
    int pointArray = 0;
    
    void switchVals(int first, int second){
        int val;
        
        val = table[first];
        table[first] = table[second];
        table[second] = val;
    }
    
    void QS::quickSort(int first, int last){
        if((last - first) < 1){
            return;
        }
        
        int pivot = medianOfThree(first, last);
        pivot = partition(first, last, pivot);
        
        quickSort(first, pivot - 1);
        quickSort(pivot + 1, last);
        
    }
    
    void QS::sortAll(){
        if(pointArray == 0 || sizeArray == 0){
            return;
        }
        
        quickSort(0, pointArray - 1);
    
    }
    
    
    int QS::medianOfThree(int left, int right){
        int middle;
        
        if (pointArray == 0 || sizeArray == 0 || left > right || left < 0 || right < left || right > pointArray - 1 || left == right){
            return -1;
        }
        
        middle = (left + right) / 2;
        
        if(table[left] > table[middle]){
            switchVals(left, middle);
        }
        if(table[right] < table[middle]){
            switchVals(right, middle);
        }
        if(table[middle] < table[left]){
            switchVals(middle, left);
        }
        
        return middle;
        
        
        
        
        
        
        
    }
    
    int QS::partition(int left, int right, int pivotIndex){
        if(pointArray == 0 || sizeArray == 0 || left < 0 || right < 0 || left == right || pivotIndex > right){
            return -1;
        }
        
        int up = left + 1;
        int down = right;
         
    
        switchVals(left, pivotIndex);
        
        do{
            while((table[up] <= table[left]) && (up < right)){
                up++;
            }
            while((table[down] > table[left]) && (down > left)){
                down--;
            }
            if(up < down){
                switchVals(up, down);
            }
            
            
            
        }while(up < down);
        
        switchVals(left, down);
        
        return down;
        
        
    }
    
    string QS::getArray() const{
        stringstream ss;
        string arrayString;
        
        if(sizeArray == 0 || pointArray == 0){
            return arrayString;
        }
        
        
        for(int i = 0; i < pointArray; ++i){
            if(i < pointArray - 1){
                ss << table[i] << ",";
            }
            else{
                ss << table[i];
            }
        }
        
        arrayString = ss.str();
        
        return arrayString;
        
        
    }
    
    int QS::getSize() const{
        return pointArray;
        
    }
    
    bool QS::addToArray(int value){
        if (table == 0){
            return false;
        }
        
        else if(pointArray == sizeArray){
            return false;
        }
        
        else{
            table[pointArray] = value;
            pointArray++;
            return true;
        }
        
    }
    
    bool QS::createArray(int capacity){
        
        
        if(capacity < 0){
            return false;
        }
        
        else if(table != 0){
            clear();
            table = new int[capacity];
            sizeArray = capacity;
            return true;
            
        }
        
        else{
            table = new int[capacity];
            sizeArray = capacity;
            return true;
        }
    }
    
    void QS::clear(){
        delete [] table;
        pointArray = 0;
        sizeArray = 0;
        table = 0;
        
        
        
    }
