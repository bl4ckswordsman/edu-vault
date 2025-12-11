const navsidebar = document.querySelector('nav');
const body = document.body;


export function show() {
    navsidebar.addEventListener('click', (event) => {
        toggleMenu();
    });

    const buttons = navsidebar.querySelectorAll('button');
    buttons.forEach((button) => {
        button.addEventListener('click', (event) => {
            event.stopPropagation();
        });
    });

    document.addEventListener('keydown', (event) => {
        if (event.key === 's' && event.ctrlKey) {
            event.preventDefault();
            toggleMenu();
        }
    });
}

function toggleMenu() {
    document.body.classList.toggle('menu-open');
}
