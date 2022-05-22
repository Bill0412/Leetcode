
import os


def slug_to_title(slug: str) -> str:
    """
    Convert a slug to a title
    """
    words = [word.capitalize() for word in slug.split('_')]
    words[0] += '.'

    is_roman = True
    for ch in words[-1]:
        if ch != 'i' and ch != 'I' and ch != 'V' and ch != 'v':
            is_roman = False
            break
    
    if is_roman:
        words[-1] = words[-1].upper()

    return ' '.join(words)

def slug_to_category(slug: str) -> str:
    """
    Convert a slug to a category
    """
    words = slug.split('_')
    return ' '.join(word.capitalize() for word in words)

def generate_toc():
    toc = '# Leetcode Solutions and Templates\n\n'
    toc += '![Leetcode Rating](https://fc.dianhsu.top/lc?user=bill04128682&loc=cn&req=rating)\n\n'
    dirs = os.listdir('./')
    dirs.sort()
    for dir in dirs:
        if not os.path.isdir(dir) or dir.startswith('.'):
            continue

        toc += '## ' + slug_to_category(dir) + '\n\n'

        problems = os.listdir(dir)
        problems.sort(key=lambda x: int(x.split('_')[0]))
        
        for problem in problems:
            path = os.path.join(dir, problem)
            toc += '- [{}]({})\n'.format(slug_to_title(problem), path)

        toc += '\n'

    return toc


if __name__ == '__main__':
    with open('README.md', 'w') as f:
        f.write(generate_toc())
