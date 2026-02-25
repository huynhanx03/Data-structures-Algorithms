class CoordinateCompression {
private:
    vector<int> original;
    vector<int> compressed;

public:
    CoordinateCompression(const vector<int>& v) {
        original = v;
        compressed = v;
        
        sort(compressed.begin(), compressed.end());
        compressed.erase(unique(compressed.begin(), compressed.end()), compressed.end());
    }

    int getCompressedValue(int val) {
        return lower_bound(compressed.begin(), compressed.end(), val) - compressed.begin();
    }

    int getOriginalValue(int compressedVal) {
        if (compressedVal >= 0 && compressedVal < compressed.size()) {
            return compressed[compressedVal];
        }
        return -1; // Out of bounds
    }

    vector<int> compressArray() {
        vector<int> res(original.size());
        for (int i = 0; i < original.size(); ++i) {
            res[i] = getCompressedValue(original[i]);
        }
        return res;
    }
};