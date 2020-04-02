# Francisco Zamora Treviño a01570484 | ITESM
install.packages("rentrez")
library(rentrez)
gene_data <- function(id) {
    print("/////////////////////")
    data <- entrez_summary("gene", id)
    print(data$nomenclaturesymbol)
    print(paste("Chromosome: ", data$chromosome))
    print(paste("Start: ", data$genomicinfo$chrstart))
    print(paste("Stop: ", data$genomicinfo$chrstop))
    print(paste("Length: ", abs(data$genomicinfo$chrstart - data$genomicinfo$chrstop)))
    print(paste("EXON COUNT: " , data$genomicinfo$exoncount))
    crossref <- entrez_link(dbfrom="gene",id=id,db="nuccore")
    seq <- entrez_fetch("nuccore", crossref$links$gene_nuccore_refseqgene,rettype="fasta")
    linked_seq_id <- entrez_link(dbfrom="gene", id=id, db="nuccore")
    as <- 0
    cs <- 0
    ts  <- 0
    gs <- 0
    repcount <- 0
    maxrepcount <- 0
    rep_nucleotide <- "Z"
    lastctx <- ""
    for (i in 1:nchar(seq)) {
        ctx <- substr(seq,i,i)
        # print(ctx)
        if (ctx == "A") {
            as <- as +1
        }
        if (ctx == "C") {
            cs <- cs+1
        } 
        if (ctx == "G") {
            gs <- gs+1 
        }
        if (ctx == "T") {
            ts <- ts + 1
        }
        if (lastctx == ctx) {
            repcount <- repcount + 1
            if (repcount > maxrepcount) {
                maxrepcount <- maxrepcount + 1
                rep_nucleotide <- ctx
            }
        } else {
            repcount <- 1
        }
        lastctx <- ctx
    }
    total_nucleotides <- (as + cs+ gs+ ts)
    print(as)
    print(paste("A percentage: ", round((as / total_nucleotides) * 100,2),"%"))
    print(paste("C percentage: ", round((cs / total_nucleotides) * 100,2),"%"))
    print(paste("T percentage: ", round((ts / total_nucleotides) * 100,2),"%"))
    print(paste("G percentage: ", round((gs / total_nucleotides) * 100,2),"%"))
    print(paste("Longest repeated nucleotide: ", rep_nucleotide , ", ", maxrepcount, " consecutive incidents"))
    print("Summary: ")
    print(data$summary)
}
gene_data(324)
gene_data(7273)
