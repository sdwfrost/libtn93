library(ape)

s <- read.dna("test.fas",format="fasta")
for(i in 1:1000000){
  d <- dist.dna(s,model="TN93")[1]
}
