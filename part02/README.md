# FLAT: Chinese NER Using Flat-Lattice Transformer

1. character-word lattice structure?
2. relative position embedding
3. 位置信息嵌入方式
4. 

## Simplify the Usage of Lexicon in Chinese NER

1. 语料库中没有，词典中有的部分
2. 模糊一些的匹配？
3. 词embedding可以用self-attention?（会降低效率）
4. 结合BERT->结合XLNET
5. the statistical data set is constructed from a combination of training and developing data of the task（合理吗）
6. es(B,M,E,S)文中是串联的，能不能用attention?
7. the  pre-trained character embeddings we used are also the same with Lattice-LSTM, which are pre-trained on Chinese Giga-Word using word2vec
8. In  these experiments, we first use a BERT encoder to obtain the  contextual  representations  of  each  sequence, and  then  concatenated  them  into  the  character representations.
9. 