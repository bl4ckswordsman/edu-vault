const openBtn = document.getElementById("openDialogBtn");
const closeBtn = document.getElementById("closeDialogBtn");
const dialog = document.getElementById("myDialog");

openBtn.addEventListener("click", () => {
    dialog.showModal();
    dialog.classList.add("is-open");
});

closeBtn.addEventListener("click", () => {
    dialog.classList.remove("is-open");

    setTimeout(() => {
        dialog.close();
    }, 300);
});