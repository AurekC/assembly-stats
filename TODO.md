# TODO

## Goals

* Create low level FASTA reader
* Read one contig/scaffold at a time and process it
* Create class to keep track of stats
* Compute basic stats on scaffolds and contigs

## Optional

* Validate sequence (should be a flag - default off)
  * Check sequence characters for non ACGTN
  * Check number of characters per line (either all the sequence on one line or 80 characters per line excepts for the last line of the sequence)
  * No whitespace in between (header of each sequence is OK)

## Extensions

* Natively read gzip/bzip2/[lzma] 
* OpenMP parallel processing

## Example from assemblathon perl script

```
                                         Number of scaffolds       2196
                                     Total size of scaffolds  459460598
                                            Longest scaffold    2883002
                                           Shortest scaffold      20020
                                Number of scaffolds > 10K nt       2196 100.0%
                               Number of scaffolds > 100K nt        969  44.1%
                                 Number of scaffolds > 1K nt       2196 100.0%
                                 Number of scaffolds > 1M nt         83   3.8%
                                Number of scaffolds > 10M nt          0   0.0%
                                          Mean scaffold size     209226
                                        Median scaffold size      83668
                                         N50 scaffold length     520525
                                          L50 scaffold count        241
                                                 scaffold %G      16.88
                                                 scaffold %C      16.89
                                                 scaffold %N       0.00
                                                 scaffold %A      33.13
                                                 scaffold %T      33.11
                                         scaffold %non-ACGTN       0.00
                             Number of scaffold non-ACGTN nt          0

                Percentage of assembly in scaffolded contigs       0.0%
              Percentage of assembly in unscaffolded contigs     100.0%
                      Average number of contigs per scaffold        1.0
Average length of break (>25 Ns) between contigs in scaffold          0

                                           Number of contigs       2196
                              Number of contigs in scaffolds          0
                          Number of contigs not in scaffolds       2196
                                       Total size of contigs  459460598
                                              Longest contig    2883002
                                             Shortest contig      20020
                                  Number of contigs > 10K nt       2196 100.0%
                                   Number of contigs > 1M nt         83   3.8%
                                  Number of contigs > 10M nt          0   0.0%
                                 Number of contigs > 100K nt        969  44.1%
                                   Number of contigs > 1K nt       2196 100.0%
                                            Mean contig size     209226
                                          Median contig size      83668
                                           N50 contig length     520525
                                            L50 contig count        241
                                                   contig %N       0.00
                                                   contig %A      33.13
                                                   contig %C      16.89
                                                   contig %G      16.88
                                                   contig %T      33.11
                                           contig %non-ACGTN       0.00
                               Number of contig non-ACGTN nt          0
```

