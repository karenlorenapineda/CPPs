#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <set>
#include <algorithm>

using namespace std;

struct Point { 
    int r, c; 
    bool operator<(const Point& o) const { return r != o.r ? r < o.r : c < o.c; }
};

typedef vector<Point> Shape;

Shape normalize(Shape s) {
    if (s.empty()) return s;
    sort(s.begin(), s.end());
    int dr = s[0].r, dc = s[0].c;
    for (auto &p : s) { p.r -= dr; p.c -= dc; }
    return s;
}

vector<Shape> get_orientations(Shape s) {
    set<Shape> variants;
    for (int flip = 0; flip < 2; ++flip) {
        for (int rot = 0; rot < 4; ++rot) {
            variants.insert(normalize(s));
            for (auto &p : s) { int tmp = p.r; p.r = p.c; p.c = -tmp; }
        }
        for (auto &p : s) p.c = -p.c;
    }
    return vector<Shape>(variants.begin(), variants.end());
}

bool solve(vector<vector<int>>& grid, int W, int H, vector<int>& remaining, const vector<vector<Shape>>& all_shapes) {
    int r = -1, c = -1;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (grid[i][j] == 0) { r = i; c = j; break; }
        }
        if (r != -1) break;
    }
    if (r == -1) return true;

    for (int i = 0; i < (int)remaining.size(); ++i) {
        if (remaining[i] <= 0) continue;
        remaining[i]--;
        for (const auto& orient : all_shapes[i]) {
            bool fits = true;
            for (const auto& p : orient) {
                int nr = r + p.r, nc = c + p.c;
                if (nr < 0 || nr >= H || nc < 0 || nc >= W || grid[nr][nc] != 0) {
                    fits = false; break;
                }
            }
            if (fits) {
                for (const auto& p : orient) grid[r + p.r][c + p.c] = 1;
                if (solve(grid, W, H, remaining, all_shapes)) return true;
                for (const auto& p : orient) grid[r + p.r][c + p.c] = 0;
            }
        }
        remaining[i]++;
    }
    return false;
}

int main() {
    ifstream file("input.txt");
    if (!file) return 1;

    vector<vector<Shape>> all_shapes_variants;
    vector<int> shape_areas;
    string line;
    
    // Leemos todo el archivo primero para procesar por secciones
    vector<string> all_lines;
    while(getline(file, line)) all_lines.push_back(line);

    // 1. Extraer Piezas
    for (int i = 0; i < all_lines.size(); ++i) {
        if (all_lines[i].find(':') != string::npos && all_lines[i].find('x') == string::npos) {
            Shape current;
            int row = 0;
            int j = i + 1;
            while (j < all_lines.size() && (all_lines[j].find('#') != string::npos || all_lines[j].find('.') != string::npos)) {
                if (all_lines[j].find(':') != string::npos) break; // Siguiente pieza
                for (int col = 0; col < (int)all_lines[j].length(); ++col) {
                    if (all_lines[j][col] == '#') current.push_back({row, col});
                }
                row++;
                j++;
            }
            if (!current.empty()) {
                shape_areas.push_back((int)current.size());
                all_shapes_variants.push_back(get_orientations(current));
            }
            i = j - 1;
        } else if (all_lines[i].find('x') != string::npos) {
            // Seccion de regiones detectada
            break;
        }
    }

    // 2. Extraer y Resolver Regiones
    int count_valid = 0;
    for (const string& rLine : all_lines) {
        if (rLine.find('x') == string::npos || rLine.find(':') == string::npos) continue;

        size_t x_pos = rLine.find('x');
        size_t col_pos = rLine.find(':');
        
        int W = stoi(rLine.substr(0, x_pos));
        int H = stoi(rLine.substr(x_pos + 1, col_pos - x_pos - 1));
        
        stringstream ss(rLine.substr(col_pos + 1));
        vector<int> counts;
        int val, area_needed = 0, idx = 0;
        while (ss >> val) {
            counts.push_back(val);
            if (idx < (int)shape_areas.size()) {
                area_needed += val * shape_areas[idx++];
            }
        }

        if (area_needed <= W * H) {
            vector<vector<int>> grid(H, vector<int>(W, 0));
            if (solve(grid, W, H, counts, all_shapes_variants)) {
                count_valid++;
            }
        }
    }

    cout << count_valid << endl;
    return 0;
}