library(Rcpp)
sourceCpp("tn93.cpp")
library(ape)

# Read FASTA
s <- read.dna("test.fas",format="fasta")
# Convert to list of character vectors
sc <- lapply(s,paste,collapse="")

ptm <- proc.time()
for(i in 1:100000){
  d1 <- tn93(sc[[1]],sc[[2]],nchar(s1),0,100)
}
print("TN93")
print(proc.time()-ptm)


ptm <- proc.time()
for(i in 1:100000){
  d2 <- dist.dna(s,model="TN93")[1]
}
print("ape dna.dist")
print(proc.time()-ptm)
