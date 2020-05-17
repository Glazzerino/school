library(RISmed)
terms <- "cancer[Title/Abstract] AND young[Title/Abstract] AND mutation[Title/Abstract] AND colon[Title/Abstract]"
# terms<- "colon/ cancer / young / mutation"
q <- EUtilsSummary(terms)
records <- EUtilsGet(q)
# print(QueryCount(query))
pubmed_data <- data.frame(abstract=records@AbstractText)
print(StructuredAbstract(pubmed_data[1],"INTRODUCTION"))