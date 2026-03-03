"""
 Problem: 433. Minimum Genetic Mutation
 Language: python3
 Runtime: 0 ms (100.00%)
 Memory: 17.1 MB (99.25%)
 Tags: Hash Table, String, Breadth-First Search
"""
class Solution:
    def minMutation(self, startGene: str, endGene: str, bank: List[str]) -> int:
        bank_set = set(bank)

        if endGene not in bank_set:
            return -1

        queue = deque([(startGene, 0)])
        visited = set([startGene])
        genes = ['A', 'C', 'G', 'T']

        while queue:
            current_gene, mutations = queue.popleft()

            if current_gene == endGene:
                return mutations
            
            for i in range(len(current_gene)): 
                for gene in genes:
                    mutated_gene = ""
                    
                    if gene != current_gene[i]:
                        mutated_gene = current_gene[:i] + gene + current_gene[i+1:] 
                    
                    if mutated_gene in bank_set and mutated_gene not in visited:
                        visited.add(mutated_gene)
                        queue.append((mutated_gene, mutations + 1)) 

        return -1
        