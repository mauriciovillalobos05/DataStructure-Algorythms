#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <random>
#include <queue>
#include <stack>
#include <chrono>

struct Person {
    std::string name;
    std::string address;
    std::string phone;
    std::string dna_code;
};

class Graph {
private:
    std::vector<Person> people;
    std::vector<std::vector<int>> adjMatrix;
public:
    Graph(int size) : adjMatrix(size, std::vector<int>(size, 0)) {}

    void addPerson(const Person& person) {
        people.push_back(person);
    }

    void addRandomConnections(int connectionsPerNode) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(1, 10);
        std::uniform_int_distribution<> nodeDist(0, people.size() - 1);

        for (int i = 0; i < people.size(); ++i) {
            for (int j = 0; j < connectionsPerNode; ++j) {
                int targetNode = nodeDist(gen);
                if (targetNode != i) {
                    int weight = dist(gen);
                    adjMatrix[i][targetNode] = weight;
                    adjMatrix[targetNode][i] = weight;
                }
            }
        }
    }

    int BFS(const std::string& target_dna) {
        std::vector<bool> visited(people.size(), false);
        std::queue<int> q;

        auto start_time = std::chrono::high_resolution_clock::now();
        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (people[node].dna_code == target_dna) {
                auto end_time = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> duration = end_time - start_time;
                std::cout << "BFS: Persona encontrada - Nombre: " << people[node].name
                          << ", ADN: " << people[node].dna_code
                          << ", Tiempo: " << duration.count() << " segundos\n";
                return node;
            }

            for (int i = 0; i < adjMatrix.size(); ++i) {
                if (adjMatrix[node][i] != 0 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }

        auto end_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end_time - start_time;
        std::cout << "BFS: No se encontró una persona con el ADN especificado, Tiempo: " << duration.count() << " segundos\n";
        return -1;
    }

    int DFS(const std::string& target_dna) {
        std::vector<bool> visited(people.size(), false);
        std::stack<int> s;

        auto start_time = std::chrono::high_resolution_clock::now();
        s.push(0);

        while (!s.empty()) {
            int node = s.top();
            s.pop();

            if (!visited[node]) {
                visited[node] = true;

                if (people[node].dna_code == target_dna) {
                    auto end_time = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> duration = end_time - start_time;
                    std::cout << "DFS: Persona encontrada - Nombre: " << people[node].name
                              << ", ADN: " << people[node].dna_code
                              << ", Tiempo: " << duration.count() << " segundos\n";
                    return node;
                }

                for (int i = 0; i < adjMatrix.size(); ++i) {
                    if (adjMatrix[node][i] != 0 && !visited[i]) {
                        s.push(i);
                    }
                }
            }
        }

        auto end_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end_time - start_time;
        std::cout << "DFS: No se encontró una persona con el ADN especificado, Tiempo: " << duration.count() << " segundos\n";
        return -1;
    }
};

int main() {
    Graph graph(10000);

    std::ifstream file("people.txt");
    std::string line;
    while (std::getline(file, line)) {
        Person person;
        std::istringstream iss(line);
        std::getline(iss, person.name, ',');
        std::getline(iss, person.address, ',');
        std::getline(iss, person.phone, ',');
        std::getline(iss, person.dna_code, ',');

        graph.addPerson(person);
    }

    graph.addRandomConnections(10);

    std::string target_dna = "DMSBCIVAQZ";

    int bfs_result = graph.BFS(target_dna);
    int dfs_result = graph.DFS(target_dna);

    if (bfs_result != -1 && dfs_result != -1) {
        std::cout << "Ambos algoritmos encontraron la persona con el ADN especificado.\n";
    } else if (bfs_result != -1) {
        std::cout << "BFS fue el único que encontró la persona con el ADN especificado.\n";
    } else if (dfs_result != -1) {
        std::cout << "DFS fue el único que encontró la persona con el ADN especificado.\n";
    } else {
        std::cout << "Ninguno de los algoritmos encontró la persona con el ADN especificado.\n";
    }

    return 0;
}
