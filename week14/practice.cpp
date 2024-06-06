#include <iostream>
#include <vector>

using namespace std;

struct edge; // Forward declaration

struct edgeNode {
    edge* edgeInfo;
    edgeNode* prev;
    edgeNode* next;
    edgeNode() {
        edgeInfo = NULL;
        prev = next = NULL;
    }
    edgeNode(edge* edgeInfo) {
        this->edgeInfo = edgeInfo;
        prev = next = NULL;
    }
};

class edgeList {
public:
    edgeList() {
        header = new edgeNode();
        trailer = new edgeNode();
        header->next = trailer;
        trailer->prev = header;
    }
    void insertEdge(edge* newEdge) {
        edgeNode* newEdgeNode = new edgeNode(newEdge);
        newEdgeNode->prev = trailer->prev;
        newEdgeNode->next = trailer;
        trailer->prev->next = newEdgeNode;
        trailer->prev = newEdgeNode;
    }
    void eraseEdge(edgeNode* delEdge) {
        delEdge->prev->next = delEdge->next;
        delEdge->next->prev = delEdge->prev;
        delete delEdge;
    }
    edgeNode* header;
    edgeNode* trailer;
};

struct vertex {
    int vertexId;
    int degree;
    vertex* prev;
    vertex* next;
    edgeList incidentEdge;

    vertex() {
        vertexId = -1;
        degree = 0;
        prev = next = NULL;
    }
    vertex(int vertexId) {
        this->vertexId = vertexId;
        degree = 0;
        prev = next = NULL;
    }
};

struct edge {
    vertex* srcVertex;
    vertex* dstVertex;
    edgeNode* srcIncidentEdge;
    edgeNode* dstIncidentEdge;
    edgeNode* totalEdgeNode;

    edge() {
        srcVertex = dstVertex = NULL;
    }
    edge(vertex* src, vertex* dst) {
        this->srcVertex = src;
        this->dstVertex = dst;
    }
};

class vertexList {
private:
    vertex* header;
    vertex* trailer;
public:
    vertexList() {
        header = new vertex();
        trailer = new vertex();
        header->next = trailer;
        trailer->prev = header;
    }
    void insertVertex(vertex* newVertex) {
        newVertex->prev = trailer->prev;
        newVertex->next = trailer;
        trailer->prev->next = newVertex;
        trailer->prev = newVertex;
    }
    void eraseVertex(vertex* delVertex) {
        delVertex->prev->next = delVertex->next;
        delVertex->next->prev = delVertex->prev;
        delete delVertex;
    }
    vertex* findVertex(int vertexId) {
        for (vertex* curVertex = header->next; curVertex != trailer; curVertex = curVertex->next) {
            if (curVertex->vertexId == vertexId) {
                return curVertex;
            }
        }
        return NULL;
    }
};

class graph {
private:
    vertexList vList;
    edgeList eList;
public:
    edge* findEdge(vertex* srcVertex, vertex* dstVertex) {
        if (srcVertex->degree < dstVertex->degree) {
            for (edgeNode* curEdge = srcVertex->incidentEdge.header->next; curEdge != srcVertex->incidentEdge.trailer; curEdge = curEdge->next) {
                if (curEdge->edgeInfo->dstVertex == dstVertex)
                    return curEdge->edgeInfo;
            }
        }
        else {
            for (edgeNode* curEdge = dstVertex->incidentEdge.header->next; curEdge != dstVertex->incidentEdge.trailer; curEdge = curEdge->next) {
                if (curEdge->edgeInfo->dstVertex == srcVertex)
                    return curEdge->edgeInfo;
            }
        }
        return NULL;
    }
    void insertVertex(int vertexId) {
        if (vList.findVertex(vertexId) != NULL)
            return;

        vertex* newVertex = new vertex(vertexId);
        vList.insertVertex(newVertex);
    }
    void eraseVertex(int vertexId) {
        vertex* delVertex = vList.findVertex(vertexId);
        if (delVertex == NULL) {
            return;
        }

        vector<edge*> edgesToDelete;
        for (edgeNode* curEdge = delVertex->incidentEdge.header->next; curEdge != delVertex->incidentEdge.trailer; curEdge = curEdge->next) {
            edgesToDelete.push_back(curEdge->edgeInfo);
        }

        for (edge* e : edgesToDelete) {
            eraseEdge(e->srcVertex->vertexId, e->dstVertex->vertexId);
        }

        vList.eraseVertex(delVertex);
    }
    void insertEdge(int srcVertexId, int dstVertexId) {
        vertex* srcVertex = vList.findVertex(srcVertexId);
        vertex* dstVertex = vList.findVertex(dstVertexId);
        if (srcVertex == NULL || dstVertex == NULL) {
            return;
        }
        if (findEdge(srcVertex, dstVertex) != NULL) {
            return;
        }

        edge* newEdge = new edge(srcVertex, dstVertex);

        srcVertex->incidentEdge.insertEdge(newEdge);
        dstVertex->incidentEdge.insertEdge(newEdge);
        eList.insertEdge(newEdge);
        newEdge->srcIncidentEdge = srcVertex->incidentEdge.trailer->prev;
        newEdge->dstIncidentEdge = dstVertex->incidentEdge.trailer->prev;
        newEdge->totalEdgeNode = eList.trailer->prev;
        srcVertex->degree++;
        dstVertex->degree++;
    }
    void eraseEdge(int srcVertexId, int dstVertexId) {
        vertex* srcVertex = vList.findVertex(srcVertexId);
        vertex* dstVertex = vList.findVertex(dstVertexId);
        if (srcVertex == NULL || dstVertex == NULL) {
            return;
        }

        edge* delEdge = findEdge(srcVertex, dstVertex);

        if (delEdge == NULL) {
            return;
        }

        srcVertex->incidentEdge.eraseEdge(delEdge->srcIncidentEdge);
        dstVertex->incidentEdge.eraseEdge(delEdge->dstIncidentEdge);
        eList.eraseEdge(delEdge->totalEdgeNode);
        srcVertex->degree--;
        dstVertex->degree--;
        delete delEdge;
    }
};

int main() {
    graph g;
    g.insertVertex(1);
    g.insertVertex(2);
    g.insertEdge(1, 2);
    g.eraseEdge(1, 2);
    g.eraseVertex(1);
    g.eraseVertex(2);
    return 0;
}
