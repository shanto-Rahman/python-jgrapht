#include <stdlib.h>
#include <stdio.h>
#include <jgrapht_capi.h>

static graal_isolate_t *isolate = NULL;
static graal_isolatethread_t *thread = NULL;

// library init

void jgrapht_thread_create() {
    if (thread == NULL) { 
        if (graal_create_isolate(NULL, &isolate, &thread) != 0) {
            fprintf(stderr, "graal_create_isolate error\n");
            exit(EXIT_FAILURE);
        }
    } 
}

void jgrapht_thread_destroy() { 
    if (thread != NULL) { 
        if (graal_detach_thread(thread) != 0) {
                fprintf(stderr, "graal_detach_thread error\n");
                exit(EXIT_FAILURE);
        }
        thread  = NULL;
        isolate = NULL;
    }
}

int jgrapht_is_thread_attached() {
    return thread != NULL; 
}

// clustering

int jgrapht_clustering_exec_k_spanning_tree(void *g, int k, void**res) { 
    return jgrapht_capi_clustering_exec_k_spanning_tree(thread, g, k, res);
}

int jgrapht_clustering_get_number_clusters(void *clustering, long long* res) { 
    return jgrapht_capi_clustering_get_number_clusters(thread, clustering, res);
}

int jgrapht_clustering_ith_cluster_vit(void *clustering, int i, void** res) { 
    return jgrapht_capi_clustering_ith_cluster_vit(thread, clustering, i, res);
}

// coloring

int jgrapht_coloring_exec_greedy(void *g, void** res) { 
    return jgrapht_capi_coloring_exec_greedy(thread, g, res);
}

int jgrapht_coloring_exec_greedy_smallestdegreelast(void *g, void** res) {
    return jgrapht_capi_coloring_exec_greedy_smallestdegreelast(thread, g, res);
}

int jgrapht_coloring_exec_backtracking_brown(void *g, void** res) { 
    return jgrapht_capi_coloring_exec_backtracking_brown(thread, g, res);
}

int jgrapht_coloring_exec_greedy_largestdegreefirst(void *g, void** res) {
    return jgrapht_capi_coloring_exec_greedy_largestdegreefirst(thread, g, res);
}

int jgrapht_coloring_exec_greedy_random(void *g, void** res) {
    return jgrapht_capi_coloring_exec_greedy_random(thread, g, res);
}

int jgrapht_coloring_exec_greedy_random_with_seed(void * g, long long int seed, void** res) {
    return jgrapht_capi_coloring_exec_greedy_random_with_seed(thread, g, seed, res);
}

int jgrapht_coloring_exec_greedy_dsatur(void *g, void** res) {
    return jgrapht_capi_coloring_exec_greedy_dsatur(thread, g, res);
}

int jgrapht_coloring_exec_color_refinement(void *g, void** res) {
    return jgrapht_capi_coloring_exec_color_refinement(thread, g, res);
}

int jgrapht_coloring_get_number_colors(void *coloring, long long* res) {
    return jgrapht_capi_coloring_get_number_colors(thread, coloring, res);
}

int jgrapht_coloring_get_vertex_color_map(void *coloring, void** res) {
    return jgrapht_capi_coloring_get_vertex_color_map(thread, coloring, res);
}

// errors

void jgrapht_clear_errno() { 
    jgrapht_capi_clear_errno(thread);
}

int jgrapht_get_errno() { 
    return jgrapht_capi_get_errno(thread);
}

char * jgrapht_get_errno_msg() { 
    return jgrapht_capi_get_errno_msg(thread);
}

// generate

int jgrapht_generate_barabasi_albert(void *g, int m0, int m, int n, long long int seed) { 
    return jgrapht_capi_generate_barabasi_albert(thread, g, m0, m, n, seed);
}

int jgrapht_generate_barabasi_albert_forest(void *g, int t, int n, long long int seed) {
    return jgrapht_capi_generate_barabasi_albert_forest(thread, g, t, n, seed);
}

int jgrapht_generate_complete(void *g, int nodes) {
    return jgrapht_capi_generate_complete(thread, g, nodes);
}

int jgrapht_generate_bipartite_complete(void *g, int a, int b) {
    return jgrapht_capi_generate_bipartite_complete(thread, g, a, b);
}

int jgrapht_generate_empty(void *g, int nodes) {
    return jgrapht_capi_generate_empty(thread, g, nodes);
}

// graph

int jgrapht_graph_create(int directed, int allowing_self_loops, int allowing_multiple_edges, int weighted, void** res) { 
    return jgrapht_capi_graph_create(thread, directed, allowing_self_loops, allowing_multiple_edges, weighted, res);
}

int jgrapht_graph_vertices_count(void *g, long long* res) { 
    return jgrapht_capi_graph_vertices_count(thread, g, res);
}

int jgrapht_graph_edges_count(void *g, long long* res) { 
    return jgrapht_capi_graph_edges_count(thread, g, res);
}

int jgrapht_graph_add_vertex(void *g, long long* res) { 
    return jgrapht_capi_graph_add_vertex(thread, g, res);
}

int jgrapht_graph_remove_vertex(void *g, long long int v, int* res) { 
    return jgrapht_capi_graph_remove_vertex(thread, g, v, res);
}

int jgrapht_graph_contains_vertex(void *g, long long int v, int* res) { 
    return jgrapht_capi_graph_contains_vertex(thread, g, v, res);
}

int jgrapht_graph_add_edge(void *g, long long int u, long long int v, long long* res) { 
    return jgrapht_capi_graph_add_edge(thread, g, u, v, res);
}

int jgrapht_graph_remove_edge(void *g, long long int e, int* res) { 
    return jgrapht_capi_graph_remove_edge(thread, g, e, res);
}

int jgrapht_graph_contains_edge(void *g, long long int e, int* res) { 
    return jgrapht_capi_graph_contains_edge(thread, g, e, res);
}

int jgrapht_graph_contains_edge_between(void *g, long long int u, long long int v, int* res) { 
    return jgrapht_capi_graph_contains_edge_between(thread, g, u, v, res);
}

int jgrapht_graph_degree_of(void *g, long long int v, long long* res) { 
    return jgrapht_capi_graph_degree_of(thread, g, v, res);
}

int jgrapht_graph_indegree_of(void *g, long long int v, long long* res) { 
    return jgrapht_capi_graph_indegree_of(thread, g, v, res);
}

int jgrapht_graph_outdegree_of(void *g, long long int v, long long* res) { 
    return jgrapht_capi_graph_outdegree_of(thread, g, v, res);
}

int jgrapht_graph_edge_source(void *g, long long int v, long long* res) { 
    return jgrapht_capi_graph_edge_source(thread, g, v, res);
}

int jgrapht_graph_edge_target(void *g, long long int v, long long* res) { 
    return jgrapht_capi_graph_edge_target(thread, g, v, res);
}

int jgrapht_graph_is_weighted(void *g, int* res) { 
    return jgrapht_capi_graph_is_weighted(thread, g, res);
}

int jgrapht_graph_is_directed(void *g, int* res) { 
    return jgrapht_capi_graph_is_directed(thread, g, res);
}

int jgrapht_graph_is_undirected(void *g, int* res) { 
    return jgrapht_capi_graph_is_undirected(thread, g, res);
}

int jgrapht_graph_is_allowing_selfloops(void *g, int* res) { 
    return jgrapht_capi_graph_is_allowing_selfloops(thread, g, res);
}

int jgrapht_graph_is_allowing_multipleedges(void *g, int* res) { 
    return jgrapht_capi_graph_is_allowing_multipleedges(thread, g, res);
}

int jgrapht_graph_get_edge_weight(void *g, long long int e, double* res) { 
    return jgrapht_capi_graph_get_edge_weight(thread, g, e, res);
}

int jgrapht_graph_set_edge_weight(void *g, long long int e, double weight) { 
    return jgrapht_capi_graph_set_edge_weight(thread, g, e, weight);
}

int jgrapht_graph_create_all_vit(void *g, void** res)  { 
    return jgrapht_capi_graph_create_all_vit(thread, g, res);
}

int jgrapht_graph_create_all_eit(void *g, void** res) { 
    return jgrapht_capi_graph_create_all_eit(thread, g, res);
}

int jgrapht_graph_create_between_eit(void *g, long long int u, long long int v, void** res) { 
    return jgrapht_capi_graph_create_between_eit(thread, g, u, v, res);
}

int jgrapht_graph_vertex_create_eit(void *g, long long int v, void** res) { 
    return jgrapht_capi_graph_vertex_create_eit(thread, g, v, res);
}

int jgrapht_graph_vertex_create_out_eit(void *g, long long int v, void** res) { 
    return jgrapht_capi_graph_vertex_create_out_eit(thread, g, v, res);
}

int jgrapht_graph_vertex_create_in_eit(void *g, long long int v, void** res) { 
    return jgrapht_capi_graph_vertex_create_in_eit(thread, g, v, res);
}

int jgrapht_graph_as_undirected(void *g, void** res) { 
    return jgrapht_capi_graph_as_undirected(thread, g, res);
}

int jgrapht_graph_as_unmodifiable(void *g, void** res) { 
    return jgrapht_capi_graph_as_unmodifiable(thread, g, res);
}

int jgrapht_graph_as_unweighted(void *g, void** res) { 
    return jgrapht_capi_graph_as_unweighted(thread, g, res);
}

int jgrapht_graph_as_edgereversed(void *g, void** res) { 
    return jgrapht_capi_graph_as_edgereversed(thread, g, res);
}

// graph test

int jgrapht_graph_test_is_empty(void *g, int* res) { 
    return jgrapht_capi_graph_test_is_empty(thread, g, res);
}

int jgrapht_graph_test_is_simple(void *g, int* res) { 
    return jgrapht_capi_graph_test_is_simple(thread, g, res);
}

int jgrapht_graph_test_has_selfloops(void *g, int* res) { 
    return jgrapht_capi_graph_test_has_selfloops(thread, g, res);
}

int jgrapht_graph_test_has_multipleedges(void *g, int* res) { 
    return jgrapht_capi_graph_test_has_multipleedges(thread, g, res);
}

int jgrapht_graph_test_is_complete(void *g, int* res) { 
    return jgrapht_capi_graph_test_is_complete(thread, g, res);
}

int jgrapht_graph_test_is_weakly_connected(void *g, int* res) { 
    return jgrapht_capi_graph_test_is_weakly_connected(thread, g, res);
}

int jgrapht_graph_test_is_strongly_connected(void *g, int* res) { 
    return jgrapht_capi_graph_test_is_strongly_connected(thread, g, res);
}

int jgrapht_graph_test_is_tree(void *g, int* res) { 
    return jgrapht_capi_graph_test_is_tree(thread, g, res);
}

int jgrapht_graph_test_is_forest(void *g, int* res) { 
    return jgrapht_capi_graph_test_is_forest(thread, g, res); 
}

int jgrapht_graph_test_is_overfull(void *g, int* res) { 
    return jgrapht_capi_graph_test_is_overfull(thread, g, res);
}

int jgrapht_graph_test_is_split(void *g, int* res) { 
    return jgrapht_capi_graph_test_is_split(thread, g, res);
}

int jgrapht_graph_test_is_bipartite(void *g, int* res) { 
    return jgrapht_capi_graph_test_is_bipartite(thread, g, res);
}

int jgrapht_graph_test_is_cubic(void *g, int* res) { 
    return jgrapht_capi_graph_test_is_cubic(thread, g, res);
}

int jgrapht_graph_test_is_eulerian(void *g, int* res) { 
    return jgrapht_capi_graph_test_is_eulerian(thread, g, res);
}

int jgrapht_graph_test_is_chordal(void *g, int* res) { 
    return jgrapht_capi_graph_test_is_chordal(thread, g, res);
}

int jgrapht_graph_test_is_weakly_chordal(void *g, int* res) { 
    return jgrapht_capi_graph_test_is_weakly_chordal(thread, g, res);
}

int jgrapht_graph_test_has_ore(void *g, int* res) { 
    return jgrapht_capi_graph_test_has_ore(thread, g, res);
}

int jgrapht_graph_test_is_trianglefree(void *g, int* res) { 
    return jgrapht_capi_graph_test_is_trianglefree(thread, g, res);
}

int jgrapht_graph_test_is_perfect(void *g, int* res) { 
    return jgrapht_capi_graph_test_is_perfect(thread, g, res);
}

int jgrapht_graph_test_is_planar(void *g, int* res) { 
    return jgrapht_capi_graph_test_is_planar(thread, g, res);
}

int jgrapht_graph_test_is_kuratowski_subdivision(void *g, int* res) { 
    return jgrapht_capi_graph_test_is_kuratowski_subdivision(thread, g, res);
}

int jgrapht_graph_test_is_k33_subdivision(void *g, int* res) { 
    return jgrapht_capi_graph_test_is_k33_subdivision(thread, g, res);
}

int jgrapht_graph_test_is_k5_subdivision(void *g, int* res) { 
    return jgrapht_capi_graph_test_is_k5_subdivision(thread, g, res);
}

// iterators

int jgrapht_it_next_long(void *it, long long* res) { 
    return jgrapht_capi_it_next_long(thread, it, res);
}

int jgrapht_it_next_double(void *it, double* res) { 
    return jgrapht_capi_it_next_double(thread, it, res);
}

int jgrapht_it_hasnext(void *it, int* res) { 
    return jgrapht_capi_it_hasnext(thread, it, res);
}

// map

int jgrapht_map_create(void** res) { 
    return jgrapht_capi_map_create(thread, res);
}

int jgrapht_map_linked_create(void** res) { 
    return jgrapht_capi_map_linked_create(thread, res);
}

int jgrapht_map_keys_it_create(void *map, void** res) { 
    return jgrapht_capi_map_keys_it_create(thread, map, res);
}

int jgrapht_map_size(void *map, long long* res) { 
    return jgrapht_capi_map_size(thread, map, res);
}

int jgrapht_map_values_it_create(void *map, void** res) { 
    return jgrapht_capi_map_values_it_create(thread, map, res);
}

int jgrapht_map_long_double_put(void *map, long long int key, double value) { 
    return jgrapht_capi_map_long_double_put(thread, map, key, value);
}

int jgrapht_map_long_long_put(void *map, long long int key, long long int value) { 
    return jgrapht_capi_map_long_long_put(thread, map, key, value);
}

int jgrapht_map_long_double_get(void *map, long long int key, double* res) { 
    return jgrapht_capi_map_long_double_get(thread, map, key, res);
}

int jgrapht_map_long_long_get(void *map, long long int key, long long* res) { 
    return jgrapht_capi_map_long_long_get(thread, map, key, res);
}

int jgrapht_map_long_contains_key(void *map, long long int key, int* res) { 
    return jgrapht_capi_map_long_contains_key(thread, map, key, res);
}

int jgrapht_map_long_double_remove(void *map, long long int key, double* res) {
    return jgrapht_capi_map_long_double_remove(thread, map, key, res);
}

int jgrapht_map_long_long_remove(void *map, long long int key, long long* res) {
    return jgrapht_capi_map_long_long_remove(thread, map, key, res);
}

int jgrapht_map_clear(void *map) { 
    return jgrapht_capi_map_clear(thread, map);
}

// matching

int jgrapht_matching_exec_greedy_general_max_card(void *g, void** res) { 
    return jgrapht_capi_matching_exec_greedy_general_max_card(thread, g, res);
}

int jgrapht_matching_exec_custom_greedy_general_max_card(void *g, int sort, void** res) {
    return jgrapht_capi_matching_exec_custom_greedy_general_max_card(thread, g, sort, res);
}

int jgrapht_matching_exec_edmonds_general_max_card_dense(void *g, void** res) {
    return jgrapht_capi_matching_exec_edmonds_general_max_card_dense(thread, g, res);
}

int jgrapht_matching_exec_edmonds_general_max_card_sparse(void *g, void** res) {
    return jgrapht_capi_matching_exec_edmonds_general_max_card_sparse(thread, g, res);
}

int jgrapht_matching_exec_greedy_general_max_weight(void *g, void** res) {
    return jgrapht_capi_matching_exec_greedy_general_max_weight(thread, g, res);
}

int jgrapht_matching_exec_custom_greedy_general_max_weight(void *g, int normalize_edge_costs, double epsilon, void** res) { 
    return jgrapht_capi_matching_exec_custom_greedy_general_max_weight(thread, g, normalize_edge_costs, epsilon, res);
}

int jgrapht_matching_exec_pathgrowing_max_weight(void *g, void** res) {
    return jgrapht_capi_matching_exec_pathgrowing_max_weight(thread, g, res);
}

int jgrapht_matching_exec_blossom5_general_max_weight(void *g, void** res) {
    return jgrapht_capi_matching_exec_blossom5_general_max_weight(thread, g, res);
}

int jgrapht_matching_exec_blossom5_general_min_weight(void *g, void** res) {
    return jgrapht_capi_matching_exec_blossom5_general_min_weight(thread, g, res);
}

int jgrapht_matching_exec_blossom5_general_perfect_max_weight(void *g, void** res) {
    return jgrapht_capi_matching_exec_blossom5_general_perfect_max_weight(thread, g, res);
}

int jgrapht_matching_exec_blossom5_general_perfect_min_weight(void *g, void** res) {
    return jgrapht_capi_matching_exec_blossom5_general_perfect_min_weight(thread, g, res);
}

int jgrapht_matching_exec_bipartite_max_card(void *g, void** res) {
    return jgrapht_capi_matching_exec_bipartite_max_card(thread, g, res);
}

int jgrapht_matching_exec_bipartite_perfect_min_weight(void *g, void *vertex_set1, void *vertex_set2, void** res) { 
    return jgrapht_capi_matching_exec_bipartite_perfect_min_weight(thread, g, vertex_set1, vertex_set2, res);
}

int jgrapht_matching_exec_bipartite_max_weight(void *g, void** res) { 
    return jgrapht_capi_matching_exec_bipartite_max_weight(thread, g, res);
}

int jgrapht_matching_get_weight(void *matching, double* res) {
    return jgrapht_capi_matching_get_weight(thread, matching, res);
}

int jgrapht_matching_get_card(void *matching, long long* res) {
    return jgrapht_capi_matching_get_card(thread, matching, res);
}

int jgrapht_matching_create_eit(void *matching, void** res) { 
    return jgrapht_capi_matching_create_eit(thread, matching, res);
}

// cleanup

int jgrapht_destroy(void *handle) { 
    return jgrapht_capi_destroy(thread, handle);
}

// mst

int jgrapht_mst_exec_kruskal(void *g, void** res) { 
    return jgrapht_capi_mst_exec_kruskal(thread, g, res);
}

int jgrapht_mst_exec_prim(void *g, void** res) {
    return jgrapht_capi_mst_exec_prim(thread, g, res);
}

int jgrapht_mst_exec_boruvka(void *g, void** res) { 
    return jgrapht_capi_mst_exec_boruvka(thread, g, res);
}

int jgrapht_mst_get_weight(void *mst, double* res) {
    return jgrapht_capi_mst_get_weight(thread, mst, res);
}

int jgrapht_mst_create_eit(void *mst, void** res) { 
    return jgrapht_capi_mst_create_eit(thread, mst, res);
}

// partition

int jgrapht_partition_exec_bipartite(void *g, int* res, void** vertex_partition1, void** vertex_partition2) { 
    return jgrapht_capi_partition_exec_bipartite(thread, g, res, vertex_partition1, vertex_partition2);
}

// scoring

int jgrapht_scoring_exec_alpha_centrality(void *g, void** res) { 
    return jgrapht_capi_scoring_exec_alpha_centrality(thread, g, res);
}

int jgrapht_scoring_exec_custom_alpha_centrality(void *g, double damping_factor, double exogenous_factor, int max_iterations, double tolerance, void** res) { 
    return jgrapht_capi_scoring_exec_custom_alpha_centrality(thread, g, damping_factor, exogenous_factor, max_iterations, tolerance, res);
}

int jgrapht_scoring_exec_betweenness_centrality(void *g, void** res) { 
    return jgrapht_capi_scoring_exec_betweenness_centrality(thread, g, res);
}

int jgrapht_scoring_exec_custom_betweenness_centrality(void *g, int normalize, void** res) { 
    return jgrapht_capi_scoring_exec_custom_betweenness_centrality(thread, g, normalize, res);
}

int jgrapht_scoring_exec_closeness_centrality(void *g, void** res) { 
    return jgrapht_capi_scoring_exec_closeness_centrality(thread, g, res);
}

int jgrapht_scoring_exec_custom_closeness_centrality(void *g, int incoming, int normalize, void** res) { 
    return jgrapht_capi_scoring_exec_custom_closeness_centrality(thread, g, incoming, normalize, res);
}

int jgrapht_scoring_exec_harmonic_centrality(void *g, void** res) { 
    return jgrapht_capi_scoring_exec_harmonic_centrality(thread, g, res);
}

int jgrapht_scoring_exec_custom_harmonic_centrality(void *g, int incoming, int normalize, void** res) { 
    return jgrapht_capi_scoring_exec_custom_harmonic_centrality(thread, g, incoming, normalize, res);
}

int jgrapht_scoring_exec_pagerank(void *g, void** res) { 
    return jgrapht_capi_scoring_exec_pagerank(thread, g, res);
}

int jgrapht_scoring_exec_custom_pagerank(void *g, double damping_factor, int iterations, double tolerance, void** res) { 
    return jgrapht_capi_scoring_exec_custom_pagerank(thread, g, damping_factor, iterations, tolerance, res);
}

// set

int jgrapht_set_create(void** res) { 
    return jgrapht_capi_set_create(thread, res);
}

int jgrapht_set_linked_create(void** res) { 
    return jgrapht_capi_set_linked_create(thread, res);
}

int jgrapht_set_it_create(void *set, void**res) { 
    return jgrapht_capi_set_it_create(thread, set, res);
}

int jgrapht_set_size(void *set, long long* res) { 
    return jgrapht_capi_set_size(thread, set, res);
}

int jgrapht_set_long_add(void *set , long long int elem) { 
    return jgrapht_capi_set_long_add(thread, set, elem);
}

int jgrapht_set_double_add(void *set, double elem) { 
    return jgrapht_capi_set_double_add(thread, set, elem);
}

int jgrapht_set_long_remove(void *set, long long int elem) { 
    return jgrapht_capi_set_long_remove(thread, set, elem);
}

int jgrapht_set_double_remove(void *set, double elem) { 
    return jgrapht_capi_set_double_remove(thread, set, elem);
}

int jgrapht_set_long_contains(void *set, long long int elem, int* res) { 
    return jgrapht_capi_set_long_contains(thread, set, elem, res);
}

int jgrapht_set_double_contains(void *set, double elem, int* res) { 
    return jgrapht_capi_set_double_contains(thread, set, elem, res);
}

int jgrapht_set_clear(void *set) { 
    return jgrapht_capi_set_clear(thread, set);
}

// vertex cover

int jgrapht_vertexcover_exec_greedy(void *g, void** res) { 
    return jgrapht_capi_vertexcover_exec_greedy(thread, g, res);
}

int jgrapht_vertexcover_exec_greedy_weighted(void *g, void *weight_vertex_map, void** res) { 
    return jgrapht_capi_vertexcover_exec_greedy_weighted(thread, g, weight_vertex_map, res);
}

int jgrapht_vertexcover_exec_clarkson(void *g, void** res) { 
    return jgrapht_capi_vertexcover_exec_clarkson(thread, g, res);
}

int jgrapht_vertexcover_exec_clarkson_weighted(void *g, void *weight_vertex_map, void** res) { 
    return jgrapht_capi_vertexcover_exec_clarkson_weighted(thread, g, weight_vertex_map, res);
}

int jgrapht_vertexcover_exec_edgebased(void *g, void** res) { 
    return jgrapht_capi_vertexcover_exec_edgebased(thread, g, res);    
}

int jgrapht_vertexcover_exec_baryehudaeven(void *g, void** res) { 
    return jgrapht_capi_vertexcover_exec_baryehudaeven(thread, g, res);    
}

int jgrapht_vertexcover_exec_baryehudaeven_weighted(void *g, void *weight_vertex_map, void** res) { 
    return jgrapht_capi_vertexcover_exec_baryehudaeven_weighted(thread, g, weight_vertex_map, res);    
}

int jgrapht_vertexcover_exec_exact(void *g, void** res) { 
    return jgrapht_capi_vertexcover_exec_exact(thread, g, res);    
}

int jgrapht_vertexcover_exec_exact_weighted(void *g, void *weight_vertex_map, void** res) { 
    return jgrapht_capi_vertexcover_exec_exact_weighted(thread, g, weight_vertex_map, res);    
}

int jgrapht_vertexcover_get_weight(void *vertex_cover, double* res) { 
    return jgrapht_capi_vertexcover_get_weight(thread, vertex_cover, res);
}

int jgrapht_vertexcover_create_vit(void *vertex_cover, void** res) { 
    return jgrapht_capi_vertexcover_create_vit(thread, vertex_cover, res);
}

// vm

void jgrapht_vmLocatorSymbol() {
    vmLocatorSymbol(thread);
}






