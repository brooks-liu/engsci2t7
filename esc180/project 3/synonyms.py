import math
import numpy as np
import re

# main functions

def cosine_similarity(vec1, vec2):
    u = []
    v = []
    for key in vec1.keys():
        if key in vec2.keys():
            u.append(vec1[key])
            v.append(vec2[key])

    if norm(vec1) != 0 and norm(vec2) != 0:
        return np.dot(u, v)/(norm(vec1)*norm(vec2))
    return -1

def build_semantic_descriptors(sentences):
    d= {}
    for sentence in sentences:  # checks every word for a list of unique words
        different_words = set(sentence)
        for word in different_words:
            if word not in d:
                d[word] = {}
        for word in different_words: # don't test duplicate words
            for word2 in sentence:  # need to test every word in the full sentence, not just the unique words
                if word == word2:
                    continue
                elif word2 in d[word]:
                    d[word][word2] += 1
                else:
                    d[word][word2] = 1
    return d

def build_semantic_descriptors_from_files(filenames):
    all_files = []
    punctuation = [",", "-", "--", ":", ";", "\n", ")", "(", "_", '"', " '", "' "]
    for file in filenames:
        new_file_str = open(file, "r", encoding="latin1").read().lower()
        for char in punctuation:
            new_file_str = new_file_str.replace(char, " ")
        new_file = re.split(r'[!.?]\s*', new_file_str)
        new_file = list(filter(("").__ne__, new_file))
        for i in range(len(new_file)):
            all_files.append(new_file[i].split())
    return build_semantic_descriptors(all_files)

def most_similar_word(word, choices, semantic_descriptors, similarity_fn):
    highest_sim = 0
    highest_sim_ind = 0
    for i in range(len(choices)):
        if word == choices[i]:
            return i
        try:
            if similarity_fn(semantic_descriptors[word], semantic_descriptors[choices[i]]) > highest_sim:
                highest_sim = similarity_fn(semantic_descriptors[word], semantic_descriptors[choices[i]])
                highest_sim_ind = i
        except KeyError:
            continue
    return choices[highest_sim_ind]

def run_similarity_test(filename, semantic_descriptors, similarity_fn):
    correct_answers = 0
    questions = open(filename, "r", encoding="latin1").read().lower().split("\n")
    for question in questions:
        words = question.split()
        if most_similar_word(words[0], words[2:], semantic_descriptors, similarity_fn) == words[1]:
            correct_answers += 1

    return correct_answers/len(questions)*100

# helper functions

def norm(vec):
    sum_of_squares = 0.0
    for x in vec:
        sum_of_squares += vec[x] * vec[x]

    return math.sqrt(sum_of_squares)
