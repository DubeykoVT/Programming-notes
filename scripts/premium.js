
document.addEventListener('DOMContentLoaded', ()=> {
  // Smooth scroll for internal links
  document.querySelectorAll('a[href^="#"]').forEach(a=>{
    a.addEventListener('click', e=>{
      e.preventDefault();
      const id = a.getAttribute('href').slice(1);
      const el = document.getElementById(id);
      if(el) el.scrollIntoView({behavior:'smooth', block:'start'});
    });
  });
  // Interactive toggles
  document.querySelectorAll('.toggle-block .toggle-btn').forEach(btn=>{
    btn.addEventListener('click', ()=>{
      const target = btn.closest('.toggle-block').querySelector('.toggle-content');
      if(!target) return;
      const is = target.style.display !== 'none';
      target.style.display = is ? 'none' : 'block';
      btn.textContent = is ? 'Показать' : 'Скрыть';
    });
  });
  // Initialize mermaid if present
  if(window.mermaid) {
    try{ mermaid.init(); }catch(e){ console.warn(e); }
  }
  // highlight.js init if present
  if(window.hljs) hljs.highlightAll();
});
