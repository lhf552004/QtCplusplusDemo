#include <QtTest/QtTest>
#include "graph.h"

class TestGraph : public QObject {
    Q_OBJECT

private slots:
    void testAddEdge();
    void testFindShortestPath();
};

// Test for the addEdge method
void TestGraph::testAddEdge() {
    Graph graph;

    // Assuming addEdge adds an edge in the adjacency list
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);

    // Check if edges are added correctly by inspecting adjacency list size
    QCOMPARE(graph.getAdjList().size(), 2);  // There should be 2 keys in adjList

    QVERIFY(graph.getAdjList().at(1).size() == 1 && graph.getAdjList().at(1)[0] == 2);  // Edge from 1 to 2
    QVERIFY(graph.getAdjList().at(2).size() == 1 && graph.getAdjList().at(2)[0] == 3);  // Edge from 2 to 3
}

// Test for the findShortestPath method
void TestGraph::testFindShortestPath() {
    Graph graph;
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(1, 3);
    graph.addEdge(3, 4);

    QTest::ignoreMessage(QtDebugMsg, "Shortest path from 1 to 3: 1 -> 3");
    graph.findShortestPath(1, 3);

    QTest::ignoreMessage(QtDebugMsg, "Shortest path from 1 to 4: 1 -> 3 -> 4");
    graph.findShortestPath(1, 4);
}

QTEST_MAIN(TestGraph)
#include "test_graph.moc"
