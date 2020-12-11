# test01

- CRF
- 二元语言模型
- The task of named entity recognition is to assign anamed entity label to every word in a sentence.
- Sentences are usually represented in the IOB format (Inside, Outside, Beginning) where every  token  is  labeled  as  B-label if  the  token  is  the beginning  of  a  named  entity,  I-label if  it  is  inside a  named  entity  but  not  the  first  token  within  the named  entity,  or  O  otherwise.
- An  important  distinction  of  our  work  from  mostprevious approaches is that we learn character-level features while training instead of hand-engineeringprefix and suffix information about words.   
- As a result, we expect the final rep-resentation of the forward LSTM to be an accuraterepresentation of the suffix of the word, and the fi-nal state of the backward LSTM to be a better rep-resentation of its prefix.   
- CoNLL-2002  and  CoNLL-2003   datasets
- 