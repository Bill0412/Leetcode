
import os


def slug_to_title(slug: str) -> str:
    """
    Convert a slug to a title
    """
    words = slug.split('_')
    words[0] += '.'
    return ' '.join(word.capitalize() for word in words)

def slug_to_category(slug: str) -> str:
    """
    Convert a slug to a category
    """
    words = slug.split('_')
    return ' '.join(word.capitalize() for word in words)

def generate_toc():
    toc = '# Leetcode Solutions and Templates\n\n'
    for dir in os.listdir('./'):
        if not os.path.isdir(dir) or dir.startswith('.'):
            continue

        toc += '## ' + slug_to_category(dir) + '\n\n'

        for problem in os.listdir(dir):
            path = os.path.join(dir, problem)
            toc += '- [{}]({})\n'.format(slug_to_title(problem), path)

        toc += '\n'

    return toc


if __name__ == '__main__':
    with open('README.md', 'w') as f:
        f.write(generate_toc())
