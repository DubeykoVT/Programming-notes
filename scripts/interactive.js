document.addEventListener('DOMContentLoaded', () => {
  const themeToggle = document.getElementById('themeToggle');
  function applyTheme(theme) {
    document.body.className = theme;
    localStorage.setItem('site-theme', theme);
    themeToggle.textContent = theme === 'dark' ? 'Светлая тема' : 'Тёмная тема';
  }
  const stored = localStorage.getItem('site-theme') || 'light';
  applyTheme(stored === 'light' ? 'light' : 'dark');

  themeToggle.addEventListener('click', () => {
    const current = document.body.className === 'light' ? 'dark' : 'light';
    applyTheme(current);
  });

  window.showExample = () => {
    const out = document.getElementById('exampleOut');
    out.textContent = 'Пример: build([5,1,7,3]) -> сумма на [0..4)=16\nПосле update(1,10) -> sum([0,4))=25';
  };

  document.querySelectorAll('a[href^="#"], a.toc-link').forEach(a=>{
    a.addEventListener('click', (e)=>{
      const href = a.getAttribute('href');
      if(href.startsWith('#')) {
        e.preventDefault();
        const el = document.querySelector(href);
        if(el) el.scrollIntoView({behavior:'smooth', block:'start'});
      }
    });
  });
});
