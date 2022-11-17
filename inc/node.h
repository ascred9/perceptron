#include <functional>
#include <memory>
#include <numeric>
#include <vector>

class Node
{
    double m_val;

    std::function<double(double)> m_f;
    std::function<double(double)> m_fp;

    class Edge
    {
        NodePtr m_inputNode;
        NodePtr m_ouputNode;
        double m_weight;

      public:
        Edge(NodePtr inputNode, NodePtr outputNode, double weight = 0):
            m_inputNode(inputNode),
            m_ouputNode(outputNode),
            m_weight(weight)
            {};

        inline void setWeight(double weight){ m_weight = weight; };
        inline double getProd(){ return m_weight * m_inputNode->getVal(); };
    };
    using EdgePtr = std::shared_ptr<Edge>;

    std::vector<Edge> m_in_nodes;
    std::vector<Edge> m_out_nodes;
    
  public:
    void addInputNode(NodePtr otherNode);
    void addOutputNode(NodePtr otherNode);
    inline double calculate() const { std::accumulate(m_in_nodes.begin(), m_in_nodes.end(), 0., []() {});};
    double getVal() const;
};

using NodePtr = std::shared_ptr<Node>;