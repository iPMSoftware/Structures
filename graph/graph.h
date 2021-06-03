#ifndef IPM_LIST
#define IPM_LIST

#include "../map/map.h"

namespace ipm {

    constexpr const int GRAPH_NORMAL = 0;
    constexpr const int GRAPH_DIRECTED = 1;

    template<typename T, int TYPE = GRAPH_NORMAL, int SIZE = 100>
    class graph_2d {
        public:
        bool add_vertex(T vertex) {
            if(has_vertex(vertex))
                return false;
            map_.put(vertex,vertex_index{vertex_count_++});
            return true;
        }
        bool delete_vertex(T vertex) {
            if(has_vertex(vertex))
                return false;
            map_.remove(vertex);
            auto vertex_id = map_.get(vertex).val_;
            for(int i = 0;i<SIZE;i++) {
                if(has_edge(vertex_id,i)) {
                    edge_count_--;
                    tab_[vertex_id][i] = false;
                    if(TYPE == GRAPH_NORMAL)
                        tab_[i][vertex_id] = false;
                }
            }
            vertex_count_--;
            return true;
        }
        bool add_edge(T vertex1, T vertex2) {
            if (!has_vertexes(vertex1,vertex2))
                return false;
            auto vertex1_id = map_.get(vertex1).val_;
            auto vertex2_id = map_.get(vertex2).val_;
            tab_[vertex1_id][vertex2_id] = true;
            if(TYPE == GRAPH_NORMAL) 
                tab_[vertex2_id][vertex1_id] = true;
            edge_count_++;
            return true;
        }
        bool delete_edge(T vertex1, T vertex2) {
            if(edge_count_ == 0)
                return false;
            if(!has_edge(vertex1,vertex2))
                return false;
            auto vertex1_id = map_.get(vertex1).val_;
            auto vertex2_id = map_.get(vertex2).val_;
            tab_[vertex1_id][vertex2_id] = false;
            if(TYPE == GRAPH_NORMAL)
                tab_[vertex2_id][vertex1_id] = false;
            edge_count_--;
            return true;
        }
        int vertexes() const {
            return vertex_count_;
        }
        int edges() const {
            return edge_count_;
        }
        private:
        struct vertex_index {
            static constexpr int kNoVertex {-1};
            int val_ {-1};

        };
        struct edge_indexes{
            vertex_index vertex1_;
            vertex_index vertex2_;
            bool is_connection() const {
                return (vertex1_.val_ != -1 && vertex2_.val_ != -1);
            }
        };
        bool has_edge(T vertex1, T vertex2) {
            if(!has_vertexes(vertex1,vertex2))
                return false;
            auto vertex1_id = map_.get(vertex1).val_;
            auto vertex2_id = map_.get(vertex2).val_;
            return tab_[vertex1_id][vertex2_id];
        }
        bool has_vertexes(T vertex1, T vertex2) {
            if(!has_vertex(vertex1))
                return false;
            if(!has_vertex(vertex1))
                return false;
            return true;
        }
        bool has_vertex(T vertex) {
            int vertex_id = map_.get(vertex).val_;
            return (vertex_id == vertex_index::kNoVertex ? false : true);
        }

        bool tab_[SIZE][SIZE];
        ipm::Map<T,vertex_index,SIZE> map_;
        int edge_count_{0};
        int vertex_count_{0};
    };

    template<typename T, int TYPE = GRAPH_NORMAL, typename IMPL = ipm::graph_2d<T,TYPE>>
    class graph {
        public:
        graph() = default;
        bool add_vertex(T vertex) {
            return impl_.add_vertex(vertex);
        }
        bool delete_vertex(T vertex) {
            return impl_.delete_vertex(vertex);
        }
        bool add_edge(T vertex1, T vertex2) {
            return impl_.add_edge(vertex1,vertex2);
        }
        bool delete_edge(T vertex1, T vertex2) {
            return impl_.delete_edge(vertex1,vertex2);
        }
        int vertexes() const {
            return impl_.vertexes();
        }
        int edges() const {
            return impl_.edges();
        }

        

        private:
        IMPL impl_;
        int size_{0};

    };  

}

#endif